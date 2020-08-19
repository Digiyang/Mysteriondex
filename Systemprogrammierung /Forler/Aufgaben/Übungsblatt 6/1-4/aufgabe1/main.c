#include<stdio.h>
#include "hello.h"
#include "bye.h"


/*
void bye(char* ch){

printf("\n bye %s !\n",ch);

}
void hello(char* ch){

printf("\n hello %s !\n",ch);

}
*/


int main()
{
	
	char *name="Hilal";
	//char *pName=name
	hello(name);
	bye(name);

	return 0;
}
