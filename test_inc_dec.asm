    .ORG $8000

start:
    LDA $2000
    ADC #1
    STA $2000
    LDA $2001
    SBC #1
    STA $2001
    LDA $42
    ADC #1
    STA $42
    JMP start

