/*
  Name: Moez, Ihr Familienname: Rjiba
  Matrikelnr: s837903
*/

#include<stdio.h>
#include<stdlib.h>
#include"queue.h"
#include"process.h"
#include<string.h>
void error(char *msg, char *file, int line){
    fprintf(stderr,"%d:%s:⎵%s:⎵%s \n", line, file, strerror(errno), msg);
    exit(EXIT_FAILURE);
}

void q_add( queue *q, process *p){
    q_node *nd;
    nd = malloc(sizeof(q_node));
    if(nd==NULL){
        error("Error!", __FILE__, __LINE__);
    }
    nd->next = NULL ;
    nd->p = p;
    if(q->start == NULL && q->end == NULL ){
            q->start = nd;
            q->end = nd;
    }
    else{
            q->end->next = nd;
            q->end = nd;
    }
}

struct process *q_remove( queue *q){
    if(q->start != NULL){
        q_node *nd = q->start;
        q->start = q->start->next;
        process *current_p = nd->p;
        free(nd);
        return current_p;
    }
    else{
        error("Empty Queue!", __FILE__, __LINE__);
    }
        
      }
    

void q_print(queue *q){
        q_node *nd ;
		nd = q->start;
		while(nd != NULL){
			p_print (nd->p);
			nd = nd->next;
		}
}

