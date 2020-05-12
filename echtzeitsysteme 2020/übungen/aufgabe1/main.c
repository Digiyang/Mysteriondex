/*
  Name: Moez, Ihr Familienname: Rjiba
  Matrikelnr: s837903
*/
#include<stdio.h>
#include "processmodel.h"
#include"process.h"
#include"queue.h"

int main (int argc, char** argv) {
    
    queue qready = {NULL, NULL} ;

    process p_1 = {1, READY} ;
    process p_2 = {2, READY} ;
    process p_3 = {3, READY} ;
    process p_4 = {4, READY} ;
    process p_5 = {5, READY} ;
    process p_6 = {6, READY} ;
    process p_7 = {7, READY} ;
    process p_8 = {8, READY} ;
    process p_9 = {9, READY} ;
    process p_10 = {10, READY} ;

    q_add (&qready , &p_1);
    q_add (&qready , &p_2);
    q_add (&qready , &p_3);
    q_add (&qready , &p_4);
    q_add (&qready , &p_5);
    q_add (&qready , &p_6);
    q_add (&qready , &p_7);
    q_add (&qready , &p_8);
    q_add (&qready , &p_9);

    p_switch_state(&p_10);
    pctx cont = {&qready, &p_10};
    
    puts ("****** 0 ******"); print(&cont); step(&cont);
    puts ("****** 1 ******"); print(&cont); step(&cont);
    puts ("****** 2 ******"); print(&cont); step(&cont);
    puts ("****** 3 ******"); print(&cont); step(&cont);
    puts ("****** 4 ******"); print(&cont); step(&cont);
    puts ("****** 5 ******"); print(&cont); step(&cont);
    puts ("****** 6 ******"); print(&cont); step(&cont);
    puts ("****** 7 ******"); print(&cont); step(&cont);
    puts ("****** 8 ******"); print(&cont); step(&cont);
    puts ("****** 9 ******"); print(&cont); step(&cont);

    return 0;
}
