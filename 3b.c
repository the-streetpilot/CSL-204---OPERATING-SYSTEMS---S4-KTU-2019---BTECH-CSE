#include<stdio.h>
#include<unistd.h>
#include<dirent.h>
#include<stdlib.h>

struct dirent *dptr;

void main(int args,char *argv[])
{
	char buff[100];
	DIR *dirp;
	printf("Enter directory name:");
	scanf("%s",buff);
	if((dirp=opendir(buff))==NULL)
	{
		printf("Given directory does not exist");
		exit(1);
	}
	while(dptr=readdir(dirp))
	{
		printf("%s\n",dptr->d_name);
	}
	closedir(dirp);
}
