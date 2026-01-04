        ORG $C000
        
        ; Pattern 1: ASL -> TAX -> LDA TABLE+1,X -> PHA -> LDA TABLE,X -> PHA -> RTS
        ASL
        TAX
        LDA TABLE+1,X
        PHA
        LDA TABLE,X
        PHA
        RTS
TABLE:  .WORD  ROUTINE0,ROUTINE1,ROUTINE2
        
        ; Pattern 2: LDA TABLEH,X -> PHA -> LDA TABLEL,X -> PHA -> RTS
        LDA TABLEH,X
        PHA
        LDA TABLEL,X
        PHA
        RTS
TABLEH: .BYTE  >ROUTINE0,>ROUTINE1,>ROUTINE2
TABLEL: .BYTE  ROUTINE0,ROUTINE1,ROUTINE2
        
ROUTINE0:
        RTS
ROUTINE1:
        RTS
ROUTINE2:
        RTS
