    .ORG $8000

.MACRO LOAD_A
    LDA #$42
.ENDM

start:
    LOAD_A
    STA $2000
    JMP start
