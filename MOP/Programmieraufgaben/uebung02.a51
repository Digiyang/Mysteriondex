
Main:

call Init
mov 
loop:
call Send
call Read
jmp loop


Init:
mov TMOD,#20h
mov SCON,#50h
mov TH1, #-6
orl PCON, #80h
setb TR1
ret

Send:
mov SBUF,#'x'
wait: jnb TI, wait
clr TI
SJMP Send
ret

Read:
jnb RI,Read
clr RI
mov R0,SBUF
call Send
ret


end
