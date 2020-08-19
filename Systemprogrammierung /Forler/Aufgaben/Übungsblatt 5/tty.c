#include <stdio.h>
#include <unistd.h>

int main (void)

{
	puts(ttyname(0));


	return 0;
}
