    .ORG $8000
    FLAG1 = 1
    FLAG2 = 0
    
    .IF FLAG1
    LDA #$11
    .IF FLAG2
    LDA #$22
    .ENDIF
    LDA #$33
    .ENDIF
    
    .IF FLAG1
    .IF FLAG2
    LDA #$44
    .ENDIF
    .ENDIF
