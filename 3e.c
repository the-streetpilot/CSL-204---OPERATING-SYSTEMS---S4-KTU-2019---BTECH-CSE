#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>

void main()
{
	char *binaryPath = "/bin/ls";
	char *arg1 = "-l";  
	char *arg2 = "/home/exam/Music/simply";
	execl( binaryPath, binaryPath, arg1, arg2, NULL);
}
