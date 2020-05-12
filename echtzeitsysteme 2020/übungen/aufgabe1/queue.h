/*
  Name: Moez, Ihr Familienname: Rjiba
  Matrikelnr: s837903
*/

#include"process.h"
#include<errno.h>

#pragma once

typedef struct q_node{
    struct q_node *next;
    process *p;
}q_node;

typedef struct queue{
    q_node *start;
    q_node *end;
}queue;

void q_add(struct queue *q, struct process *p);
struct process *q_remove(struct queue *q);
void q_print(struct queue *q);
void error(char *msg, char *file, int line);
