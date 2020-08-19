
mov r1,#03h
mov r0,#05h

mov dptr,#label1

main:
mov a,r0
setb p2.0
setb p2.1
setb p2.2
acall display
mov p0,a
acall DELAY
clr p2.0
clr p2.1
clr p2.2
mov a,r1
setb p2.1
setb p2.2
acall display
mov p0,a
acall DELAY
clr p2.1
clr p2.2
sjmp main

display:
movc a,@a+dptr
ret

label1:
DB 3FH
DB 06H
DB 5BH
DB 4FH
DB 66H
DB 6DH
DB 7DH
DB 07H
DB 7FH
DB 6FH
DB 01011111b
DB 01111100b
DB 01011000b
DB 01011110b
DB 01111011b
DB 01110001b

DELAY: MOV R3,#02H
DEL1: MOV R2,#0FAH
DEL2: DJNZ R2,DEL2
DJNZ R3,DEL1
RET
end