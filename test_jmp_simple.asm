        ORG $C000
        
        ; Simple Pattern 1 test
        ASL
        TAX
        LDA TABLE+1,X
        PHA
        LDA TABLE,X
        PHA
        RTS
        
TABLE:  .WORD  $1234,$5678,$9ABC
