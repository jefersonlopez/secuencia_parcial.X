secuencia:
    movlw   .2
    movwf   repeticiones
bucle:
    clrf    pos_tabla
    movlw   .2
    movwf   num_secuencias
bucle_2:
    movlw   .11
    movwf   ciclos_secuencia
bucle_3:
    call    cargar_valores
    incf    pos_tabla
    call    retardo_500ms
volver_verificar:
    decfsz  ciclos_secuencia
    goto    bucle_3
    decfsz  num_secuencias
    goto    bucle_2
    decfsz  repeticiones
    goto    bucle
    return

cargar_valores:
    movf    pos_tabla,W
    call    tabla
    movwf   PORTC
    movf    pos_tabla,W
    call    tabla2
    movwf   PORTD
    return


tabla:
    addwf   PCL,F
;primer secuencia PORTC
    retlw   0x7F
    retlw   0XFE
    retlw   0XFC
    retlw   0XF8
    retlw   0XF0
    retlw   0XE0
    retlw   0XF0
    retlw   0XF8
    retlw   0XFC
    retlw   0XFE
    retlw   0X7F
;segunda secuencia PORTD
    retlw   0X01
    retlw   0X02
    retlw   0X04
    retlw   0X08
    retlw   0X90
    retlw   0X60
    retlw   0X90
    retlw   0X08
    retlw   0X04
    retlw   0X02
    retlw   0X01

tabla2:
    addwf   PCL,F
;primer secuencia
    retlw   0x00
    retlw   0X00
    retlw   0X01
    retlw   0X03
    retlw   0X07
    retlw   0X0F
    retlw   0X07
    retlw   0X03
    retlw   0X01
    retlw   0X00
    retlw   0X00
;segunda secuencia
    retlw   0X08
    retlw   0X04
    retlw   0X02
    retlw   0X01
    retlw   0X00
    retlw   0X00
    retlw   0X00
    retlw   0X01
    retlw   0X02
    retlw   0X04
    retlw   0X08
    
   


