#include <stdio.h>

int a[100];
int n;
int b[100];
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

void linear()
{
int i=0;
printf("enter the value to be searched");
int key;
scanf("%d",&key);

for ( i=0;i<n;i++)
{
if (key==a[i])
{
printf ("element found at position : %d \n",i+1);
break;
}
}
if(key!=a[i] && i==n)
{
printf("element not found\n");
}
}


void binary()
{
bubble();
int count=0;
printf("enter the value to be searched");
int key;
scanf("%d",&key);
int mid;
int low=0;
int high=n-1;
while (low<=high)
{
mid = (low+high)/2;
if (key==b[mid])
{
printf ("element found at position : %d \n",mid+1);
count++;
break;
}	
else if(key<b   [mid])
{
high=mid-1;
}
else
{ 
low=mid+1;
}

}
if (count==0)
printf("element not found\n");
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
printf("enter your choice : 1. for linear search 2. binary search : ");
scanf("%d",&ch);

if (ch==1)
{
linear();
}
else if(ch==2)
{

binary();
}
else
{
break;
}
}
}




