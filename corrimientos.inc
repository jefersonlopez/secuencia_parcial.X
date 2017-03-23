corrimiento_derecha:
    bcf	    STATUS,C
    movlw   .16
    movwf   corrimientos
    movlw   0x00
    movwf   PORTC
    movlw   0x80
    movwf   PORTD
    p_d:
    movf    PORTB,w
    movwf   valor_secuencia
    call    retardo_5ms
    call    com
    btfss   comprobaciones,1
    return
    decfsz  valor_secuencia
    goto    $-5
    rrf	    PORTD
    rrf	    PORTC
    decfsz  corrimientos
    goto    p_d
    return
    
corrimiento_izquierda:
    bcf	    STATUS,C
    movlw   .16
    movwf   corrimientos
    movlw   0x01
    movwf   PORTC
    movlw   0x00
    movwf   PORTD
    p_i:
    movf    PORTB,w
    movwf   valor_secuencia
    call    retardo_5ms
    call    com
    btfss   comprobaciones,2
    return
    decfsz  valor_secuencia
    goto    $-5
    rlf	    PORTC
    rlf	    PORTD
    decfsz  corrimientos
    goto    p_i
    return
   
com:
    clrf    comprobaciones
    movlw   0x00
    xorwf   PORTE,w
    btfsc   STATUS,Z
    bsf	    comprobaciones,0
    movlw   0x01
    xorwf   PORTE,w
    btfsc   STATUS,Z
    bsf	    comprobaciones,1
    movlw   0x02
    xorwf   PORTE,w
    btfsc   STATUS,Z
    bsf	    comprobaciones,2
    movlw   0x03
    xorwf   PORTE,w
    btfsc   STATUS,Z
    bsf	    comprobaciones,3
    return
    
    


