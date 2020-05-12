/*
 *Name: Moez, Ihr Familienname: Rjiba
 *Matrikelnr: s837903
 */

#include<stdio.h>
#include"process.h"

void p_switch_state(process *p){
    if(p->p_state==RUNNING){
        p->p_state=READY;
    }
    else{
        p->p_state=RUNNING;
    }
}

void p_print(process *p){
    if(p->p_state==READY){
        printf("PID = %u is ready \n" , p->p_id);
    }
    else{
        printf("PID = %u is running \n", p->p_id);
    }
}
