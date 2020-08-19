;
$DATE (24.11.2017)
$TITLE ( )
$PAGELENGTH(56)
$PAGEWIDTH(150)
$DEBUG
$XREF
$NOLIST
$MOD51
$LIST
;


JMP Main

ORG 0Bh                            ; Adresse von Timer0 interrupt
CPL P3.7                           ; Port 3.7 komplementieren
RETI                               ; return von Interrupt

Main:
MOV SCON, #50h                     ; set serial mode1 (8Bit)    
MOV TMOD, #28h                     ; set timer 1 mode 2
mov TH1, #0f4h
mov TL1, #0f4h
orl PCON, #80h 
SETB TR1

ACALL Serial_Init                  ; initialisieren
ACALL Timer_Init


Start:
ACALL Serial_Read                  ; Zahl (in Hex) einlesen
JMP Start

Serial_Init:
MOV A, PCON                        ; Baud-Rate setzen
SETB ACC.7                         ; start Timer1
MOV PCON, A

Timer_Init:
MOV A, TMOD
CLR ACC.3                          ; Timer0 aktivieren
SETB ACC.1                         ; Timer0 auf Mode2 setzen
CLR ACC.0
MOV TMOD, A

SETB ET0                           ; Interrupt für Timer0 aktivieren
SETB EA                            ; Interrupt allgemein aktivieren

MOV TH0, #3Ch
SETB TR0
RET

Serial_Read:
JNB RI, $
CLR RI
MOV A, SBUF
MOV TH0, A
mov SBUF,A
RET
end
 