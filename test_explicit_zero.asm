    .ORG $8000
PIRQH = 0
    LDA #0
    STA $100
    LDA #PIRQH
    STA $200
    LDA #$0
    STA $300
