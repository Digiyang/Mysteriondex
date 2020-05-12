/*
  Name: Moez, Ihr Familienname: Rjiba
  Matrikelnr: s837903
*/


#include"process.h"
#include"queue.h"


int main()
{
    
    queue qo = {NULL, NULL} ;
    queue *q = &qo ; 
  //comment from line 11 to line 26 to test else condition "empty queue"  
    process process_1 = {81, RUNNING} ;
    process process_2 = {27, RUNNING} ;
    process process_3 = {73, READY} ;

    process *p_1  = &process_1;
    process *p_2  = &process_2;
    process *p_3  = &process_3;
    
    p_switch_state(p_1);

/*add process to queue*/
    /*Testing error Function*/
  /*q_add(q,p_1);
    q_add(q,p_2);
    q_add(q,p_3);
*/
/*print queue*/
    q_print(q);
    puts("-----------\n");
    q_remove(q);
    p_switch_state(p_2);
    q_print(q);

}