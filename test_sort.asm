    .ORG $8000
    ADC #$01
    AND #$02
    ASL A
    BCC label1
    BEQ label2
    BRK
    CLC
    CMP #$03
    DEC $10
    EOR #$04
    INC $20
    JMP $9000
    JSR $8000
    LDA #$05
    LDX #$06
    LDY #$07
    LSR A
    NOP
    ORA #$08
    PHA
    PHP
    PLA
    PLP
    ROL A
    ROR A
    RTI
    RTS
    SBC #$09
    SEC
    SED
    SEI
    STA $30
    STX $40
    STY $50
    TAX
    TAY
    TSX
    TXA
    TXS
    TYA
label1:
label2:
    RTS
