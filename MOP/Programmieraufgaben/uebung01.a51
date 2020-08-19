;
$DATE (27.10.2017)
$TITLE (Taste)
$PAGELENGTH(56)
$PAGEWIDTH(150)
$DEBUG
$XREF
$NOLIST
$MOD51
$LIST
;
main:
drucken:
jb p3.4, drucken
mov A, p0
cpl A
mov p0, A                             
mov r1, #000h
loop01:
mov r0, #000h
loop00:
djnz r0, loop00
djnz r1, loop01

freilassen:
jnb p3.4, freilassen
mov r1, #000h
loop11:
mov r0, #000h
loop10:
djnz r0, loop10
djnz r1, loop11

jmp main
end
