    .ORG $1000
    LDA forward_var
    JMP forward_label
    LDA #$01
    STA $2000
forward_var EQU $42
forward_label:
    RTS
