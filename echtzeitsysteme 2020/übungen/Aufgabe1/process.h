/*
 *Name: Moez, Ihr Familienname: Rjiba
 *Matrikelnr: s837903
 */

#include<stdio.h>
#include<stdint.h>

#pragma once

typedef enum {READY,RUNNING}state;

typedef struct process{
    
    uint32_t p_id;
    state p_state;
}process;

void p_switch_state(struct process *p);
void p_print(struct process *p);
