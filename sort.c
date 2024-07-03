#include <stdio.h>

int a[100];
int n;
int b[100];
int c[100];

void bubble()
{

for(int i=0;i<n;i++)
{
    b[i]=a[i];
}

for(int i=0;i<n-1;i++)
{
    for(int j=0;j<n-i-1;j++)
    {
        if(b[j]>b[j+1])
        {
            b[j]=b[j+1]+b[j];
            b[j+1]=b[j]-b[j+1];
            b[j]=b[j]-b[j+1];
        }
    }
}
printf(" sorted list is: ");
for(int i=0;i<n;i++)
{

    printf("%d ",b[i]);

}
printf("\n");
}



void insert()
{

    for(int i   =0;i<n;i++)
    {
        c[i]=a[i];
    }

    int temp;
    for(int i=0;i<n;i++)
    {
        temp=c[i];
        int j = i-1;
        while (temp<=c[j]&&j>=0)
        {
            c[j+1]=c[j];
            j--;
        }
        c[j+1]=temp;
    }

    printf(" sorted list is: ");
    for(int i=0;i<n;i++)
    {

        printf("%d ",c[i]);

    }
    printf("\n");


}
void main()
{

printf("enter the size of the array");
scanf("%d",&n);
printf("enter the elements into array:");
for(int i=0;i<n;i++)
{
scanf("%d",&a[i]);
}

while(1)
{
int ch;
printf("enter your choice : 1. for bubble sort 2. insertion sort : ");
scanf("%d",&ch);

if (ch==1)
{
bubble();
}
else if(ch==2)
{
insert();
}
else
{
break;
}
}
}




