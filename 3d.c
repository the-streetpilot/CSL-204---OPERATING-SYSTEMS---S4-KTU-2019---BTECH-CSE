#include<stdio.h>
#include<sys/wait.h>
#include<unistd.h>

void main()
{
	if(fork()==0)
	{
		printf("\nHC: Hello from Child\n");
	}
	else
	{
		printf("\nHP: Hello from Parent\n");
		wait(NULL);
		printf("\nCT: Child has terminated\n");
	}
	printf("\nBye\n");
}
