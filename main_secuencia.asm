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


    endc

    org .0
    call osc_conf   ;configura el oscilador
    call port_conf  ;configura los puertos
    
inicio:
    
    movlw   0x00
    xorwf   PORTE,w
    btfsc   STATUS,Z
    call    op1
    movlw   0x01
    xorwf   PORTE,w
    btfsc   STATUS,Z
    call    secuencia
    movlw   0x02
    xorwf   PORTE,w
    btfsc   STATUS,Z
    call    op3
    movlw   0x03
    xorwf   PORTE,w
    btfsc   STATUS,Z
    call    op4
    goto    inicio
    
    op1:
    movlw   0x01
    movwf   PORTC
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
    end





