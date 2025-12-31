    .ORG $8000

start:
    LDA #$42    ; Load value 42 into accumulator
    STA $2000   ; Store it at address $2000
    LDA #$00    ; Load zero
    STA $2001   ; Store zero at $2001
    JMP start   ; Jump back to start
    ; This is a comment on its own line
