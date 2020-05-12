/*
  Name: Moez, Ihr Familienname: Rjiba
  Matrikelnr: s837903
*/

#include<stdio.h>
#include<stdlib.h>
#include"processmodel.h"

void print (pctx *ctx){
    puts("\nprocess is running:  \n");
    p_print(ctx->running);
    puts("\nprocess is ready:  \n");
    q_print(ctx->qready);
}

void step (pctx *ctx){
    ctx->running->p_state = READY;
    q_add(ctx->qready, ctx->running);
    ctx->running = q_remove(ctx->qready);
    ctx->running->p_state = RUNNING;
}