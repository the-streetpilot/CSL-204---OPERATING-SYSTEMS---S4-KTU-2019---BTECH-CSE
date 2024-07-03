//Binary Search Tree

#include<stdio.h>
#include<stdlib.h>

struct tree                  
{
    int data;
    struct tree *left;
    struct tree *right;
}*root,*temp,*q,*p;

struct tree *root=NULL;

void create(int item)                             
{
    root=(struct tree *)malloc(sizeof(struct tree));
    root->data=item;
    root->left=NULL;
    root->right=NULL;
}

void insert(int item)
{
    p=root;
    q=NULL;
    while(p!=NULL)                             
    {
        if(p->data<item)
        {
            q=p;
            p=p->right;
        }
        else if(p->data>item)
        {
            q=p;
            p=p->left;
        }
        else
        {
            printf("Already Exists");
            break;
        }
    }
    temp = (struct tree *)malloc(sizeof(struct tree));                
    temp->data=item;
    temp->left=NULL;
    temp->right=NULL;
    if(q==NULL)                            
    {
        root=temp;
    }
    else if(q->data<item)
    {
        q->right=temp;
    }
    else
    {
        q->left=temp;
    }
}

void preorder(struct tree *temp)                     
{
    if(temp!=NULL)
    {
        printf("%d->",temp->data);
        preorder(temp->left);
        preorder(temp->right);
    }
}

void postorder(struct tree *temp)                   
{
    if(temp!=NULL)
    {
        postorder(temp->left);
        postorder(temp->right);
        printf("%d->",temp->data);
    }
}

void inorder(struct tree *temp)                  
{
    if(temp!=NULL)
    {
        inorder(temp->left);
        printf("%d->",temp->data);
        inorder(temp->right);
    }
}

void main()                             
{
    int item,n,ch;
    printf("Creating tree, Enter Data for Root: ");
    scanf("%d",&item);
    create(item);
    while(1)                                
    {
        printf("Enter Your Choice:\n1.Insert\n2.Preorder\n3.Postorder\n4.Inorder\n5.Exit\n:");
        scanf("%d",&ch);
        if(ch==1)
        {
            printf("Enter number of leaves: ");
            scanf("%d",&n);
            for (int i = 0; i < n; i++)
            {
                printf("Enter Data: ");
                scanf("%d", &item);
                insert(item);
            }
        }
        else if(ch==2)
        {
            preorder(root);
            printf("\n");
        }
        else if(ch==3)
        {
            postorder(root);
            printf("\n");
        }
        else if(ch==4)
        {
            inorder(root);
            printf("\n");
        }
        else
            break;
    }
}
