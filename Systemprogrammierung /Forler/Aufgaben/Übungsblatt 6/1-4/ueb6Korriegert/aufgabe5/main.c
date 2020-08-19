#include <stdio.h>
#include <stdlib.h>

int main(int args, char *argv[])
{
#ifdef BananaMac
    fputs("Banana Mac is not supported\n", stderr);
    return 1;
#endif

    if(args != 4)
    {
        fputs("usage: multiplatform <number> <number> <number>\n", stderr);
        return 1;
    }


#ifdef BirneX
    long a, b, c;

    a = atol(*(argv+1));
    b = atol(*(argv+2));
    c = atol(*(argv+3));

    printf("Sum: %ld\n", a+b+c);
#elif defined LockedBSD
    int a, b, c;

    a = atoi(*(argv+1));
    b = atoi(*(argv+2));
    c = atoi(*(argv+3));

    printf("Sum: %d\n", a+b+c);
#elif defined Doors10
    short a, b, c;

    a = atoi(*(argv+1));
    b = atoi(*(argv+2));
    c = atoi(*(argv+3));

    printf("Sum: %hd\n", a+b+c);
#endif

    return 0;
}
