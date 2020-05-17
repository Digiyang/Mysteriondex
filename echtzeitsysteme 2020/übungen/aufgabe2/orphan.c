/*Links:https://pubs.opengroup.org/onlinepubs/009695399/functions/getpwuid.html */

#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<pwd.h>
#include<sys/types.h>

#define CHILD 0

void handler(){/*exit handler + Process' Owner*/
    uid_t pid = geteuid();
    struct passwd *p_owner;
    p_owner = getpwuid(pid);
    printf("\nGoodbye %s :)\n",p_owner ->pw_name);
 } 


void orphan(){ /*Orphan function code*/
    int p=fork();
    
    if(p == CHILD){/*Child process code*/
        printf("\nChild:  %u / %u\n", getpid(), getppid() );
        sleep(2);
    }
    else if(p > CHILD) {/*Parent process code*/
        printf("\nFather: %u / %u\n", getpid(),  getppid() );
        sleep(1);
        atexit(handler);
    }
    else{/*Error handling code*/
        perror("Fork failed!\n");
    }
return;
 }

int main(){
    orphan();
    return errno;
}

