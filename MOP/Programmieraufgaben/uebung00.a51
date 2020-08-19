;
$DATE (13.10.2017)
$TITLE ( )
$PAGELENGTH(56)
$PAGEWIDTH(150)
$DEBUG
$XREF
$NOLIST
$MOD51
$LIST

marke:
mov p0,#0feh
    
    loop:
    djnz r0,loop
    
    loop10:
    djnz r0,loop10
    
mov p0,#0ffh
  
jmp marke
end