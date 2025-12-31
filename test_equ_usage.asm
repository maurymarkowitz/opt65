    .ORG $8000
    
    PATSIZ EQU $1
    LOMEM = $80
    
start:
    LDA #PATSIZ
    STA LOMEM
    LDA #LOMEM
