    .ORG $8000
    DEBUG = 1
    VERSION = 2
    
    .IF DEBUG
    LDA #$FF
    STA $D000
    .ENDIF
    
    .IF VERSION-1
    LDA #$01
    .ENDIF
    
    .IF VERSION-2
    LDA #$02
    .ENDIF
