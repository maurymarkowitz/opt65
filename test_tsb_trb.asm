    .ORG $8000

start:
    LDA $2000
    ORA #$01
    STA $2000
    LDA $2001
    AND #$FE
    STA $2001
    LDA $42
    ORA #$04
    STA $42
    JMP start

