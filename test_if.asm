    .ORG $8000
    FLAG = 1
    
    .IF FLAG
    LDA #$42
    STA $2000
    .ENDIF
    
    .IF 0
    LDA #$99
    STA $2001
    .ENDIF
    
    .IF FLAG
    LDA #$AA
    STA $2002
    .ENDIF
