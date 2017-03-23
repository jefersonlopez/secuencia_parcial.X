retardo_5ms:
    movlw .20   ;   1
    movwf cont1 ;   1
ciclo2:
    movlw .8   ;   1
    movwf cont2 ;   1
ciclo1:
    movlw .19   ;   1
    movwf cont3 ;   1
    decfsz cont3;   1(2)
    goto $-1    ;   2
    decfsz cont2;   1(2)
    goto ciclo1 ;   2
    decfsz cont1;   1(2)
    goto ciclo2 ;   2
    return

retardo_50ms:
    movlw   .20
    movwf   cont_seg
    call    retardo_5ms
    decfsz  cont_seg
    goto    $-2
    return

retardo_500ms:
    movlw   .100
    movwf   cont_seg
    call    retardo_5ms
    decfsz  cont_seg
    goto    $-2
    return




