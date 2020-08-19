#include <unistd.h>
#include <stdio.h>
/*
sync (1)             - Synchronize cached writes to persistent storage
sync (2)             - commit filesystem caches to disk
*/

int main(){

	sync();

	return 0 ;
}

