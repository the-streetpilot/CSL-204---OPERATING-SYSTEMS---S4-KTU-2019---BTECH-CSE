#include<stdio.h>
#include<sys/stat.h>

void main()
{
	struct stat sfile;
	stat("simply",&sfile);
	printf("st_mode=%o",sfile.st_mode);
}
