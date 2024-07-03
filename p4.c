#include <stdio.h>
#include <string.h>

struct stack
{
    char a[100];
    int top;
    int size;
}s;

void pop()
{
    if (s.top==-1)
        printf("the stack is empty\n");
    else
        s.top--;
}

void push(char ch)
{
    if(s.top==s.size-1)
        printf("overflow");
    else
    {
        s.top++;
        s.a[s.top]=ch;
    }
}

int pre(char ch)
{
    switch(ch)
    {
    case '^':
        return 3;
        break;
    case '+':
    case '-':
        return 1;
        break;
    case '*':
    case '/':
        return 2;
        break;
    case '(':
        return 0;
        break;
    }   
}

void main()
{
    char in[100];
    char po[100];
    int j=0;
    char ch;
    s.top =-1;


    printf(" your infix expression \n");
    scanf("%s", in);
    s.size=strlen(in);

    for(int i=0;i<s.size;i++)
    {
        ch = in[i];
        switch(ch)
        {
            case 'a':
            case 'b':
            case 'c':
            case 'd':
            case 'e':
            case 'f':
                po[j]=ch;
                j++;
            break;
            case '+':
            case '-':
            case '*':
            case '^':
            case '/':
                if (s.top==-1)
                    push(ch);
                else
                { 
                    while(pre(ch)<=pre(s.a[s.top]))
                    {
                        po[j]=s.a[s.top];
                        j++;
                        pop();
                    }
                    push(ch);
                }
                break;
            case'(':
                push(ch);
                break;
            case')':
                while (s.a[s.top]!='(')
                {
                    po[j]=s.a[s.top];
                    j++;
                    pop();
                }
                pop();
                break;
        }
    }

    while(s.top!=-1)
    {
        po[j]=s.a[s.top];
        j++;
        pop();
    }

    printf("the postfix is\n");
    for(int i=0;i<j;i++)
    {
    printf("%c",po[i]);
    }
}

