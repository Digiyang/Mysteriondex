/*
  Name: Moez, Ihr Familienname: Rjiba
  Matrikelnr: s837903
*/

#include"queue.h"
#pragma once

typedef struct pctx {
    queue *qready;
    process *running;
} pctx;

void print (pctx *ctx);
void step (pctx *ctx);