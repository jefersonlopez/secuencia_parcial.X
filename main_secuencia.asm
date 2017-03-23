LIST p = 16f887

    #include "p16f887.inc"

    cblock  0x20
; declaracion de variables
    cont1           ;variable usada para retardos
    cont2           ;variable usada para retardos
    cont3           ;variable usada para retardos
    retardo         ;variable usada para retardos    
    cont_seg        ;variable usada para retardos
    pos_tabla       ;posicion de inicio de la tabla
    ciclos_secuencia ;nuemro de ciclos por secuencia
    num_secuencias  ;numero de secuencias
    repeticiones    ;numero de veces que se repite la secuencia
    valor_secuencia ;indica el retardo de la secuencia
    corrimientos    ;indica cuantos corrimientos se haran
    comprobaciones  ;variable usada para almacenar el resultado de verificacion


    endc

    org .0
    call osc_conf   ;configura el oscilador
    call port_conf  ;configura los puertos
    
inicio:
    
revisar:
    movlw   0x00
    xorwf   PORTE,w
    btfsc   STATUS,Z
    call    op1
    movlw   0x01
    xorwf   PORTE,w
    btfsc   STATUS,Z
    call    corrimiento_derecha
    movlw   0x02
    xorwf   PORTE,w
    btfsc   STATUS,Z
    call    corrimiento_izquierda
    movlw   0x03
    xorwf   PORTE,w
    btfsc   STATUS,Z
    call    secuencia
    goto    inicio
    
    op1:
    movlw   0x00
    movwf   PORTC
    movwf   PORTD
    return
    op2:
    movlw   0x0f
    movwf   PORTC
    return
    op3:
    movlw   0xf0
    movwf   PORTC
    return
    op4:
    movlw   0xff
    movwf   PORTC
    return
    

#include "configuracion.inc"
#include "retardos.inc"
#include "secuencia.inc"
#include "corrimientos.inc"
    end





