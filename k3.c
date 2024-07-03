#include <stdlib.h>
#include <stdio.h>

struct node
{
	int data;
	struct node *next;
}*head,*temp,*p, *q;



void display()
{
p=head;
while(p!=NULL)
{
	printf("%d->",p->data);
	p=p->next;	
}
printf("\n");
}

void sllinsertkey()
{
p=head;
int key;
printf("enter key value");
scanf("%d",&key);
int d;
temp=(struct node*)malloc(sizeof(struct node));
printf("enter the data in node");
scanf("%d",&d);
while (p->next!=NULL && p->data!=key)
{
p = p->next;
}
temp->data=d;
temp->next=p->next;
p->next=temp;
display();
}

void slldeletekey()
{
p=head;
int key;
printf("enter key value");
scanf("%d",&key);
while (p!=NULL && p->data!=key)
{
q=p;
p = p->next;
}
q->next = p->next;
free(p);
display();
}

void slldeletefirst()
{
p=head;
if(p==NULL)
{
printf("Empty List");
}
else
{
q=p->next;
head=q;
}
free(p);
display();
}

void slldeletelast()
{
p=head;
if(p==NULL)
{
printf("Empty List");
}
else
{
while (p->next!=NULL)
{
q=p;
p = p->next;
}
free(p);
q->next=NULL;
}
display();
}

void sllinsertfirst()
{
int d;
temp=(struct node*)malloc(sizeof(struct node));
printf("enter the data in node");
scanf("%d",&d);
temp->data=d;
temp->next=head;
head=temp;
display();
}

void sllinsertlast()
{
p=head;
int d;
temp=(struct node*)malloc(sizeof(struct node));
printf("enter the data in node");
scanf("%d",&d);
while (p->next!=NULL)
{
p = p->next;
}
temp->data=d;
temp->next=NULL;
p->next=temp;
display();
}

void create(int n)
{
int d,i;
for(i=1;i<=n;i++)
	{
	printf("enter the data in node");
	scanf("%d",&d);
	
	temp=(struct node*)malloc(sizeof(struct node));
	temp->data=d;
	temp->next=NULL;
	if(i==1)
	{
	head=p=temp;
	}
	else
	{
	p->next=temp;
	p=temp;
	}
	}
	display();
}

void main()
{
	int n,i,d,ch;
	printf("enter the no: of nodes in SLL");
	scanf("%d",&n);
	create(n);
	while(1)
	{
	printf("enter your choice : 1.insert first 2. insert last 3. insert at key 4.delete first 5.delete last 6.delete at key ; any other key to exit :");
	scanf("%d",&ch);
	if (ch==1)
	sllinsertfirst();
	else if(ch==2)
	sllinsertlast();
	else if(ch==3)
	sllinsertkey();
	else if(ch==4)
	slldeletefirst();
	else if(ch==5)
	slldeletelast();
	else if(ch==6)
	slldeletekey();
	else
	break;
	}
}



