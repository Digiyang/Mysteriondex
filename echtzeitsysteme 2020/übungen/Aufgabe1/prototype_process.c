/*
 *Name: Moez, Ihr Familienname: Rjiba
 *Matrikelnr: s837903
 */

#include<stdio.h>
#include"process.h"

int main(){
    
    process process1 = {8,RUNNING};
    process *p = &process1;
    p_print(p);
    p_switch_state(p);
    p_print(p);
    
    return 0;
}