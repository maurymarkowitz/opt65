    .ORG $8000
start:
    LDA #$42
    JMP start
    JMP near_label
    .BYTE 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
    .BYTE 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0
near_label:
    RTS
