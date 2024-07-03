#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

struct stack
{
    int a[100];
    int top;
    int size;
}s;

int pop()
{
    int x;
    if (s.top==-1)
        printf("End of operation");
    else
    {
        x=s.a[s.top];
        s.top--;
        return x;
    }  
}

void push(int num)
{
    if(s.top==s.size-1)
        printf("Overflow");
    elses
    {
        s.top++;
        s.a[s.top]=num;
    }
}

void main()
{
    int res,num;
    char po[100];
    int i=0;
    char ch;
    int x,y;
    int result;
    s.top=-1;

    printf("enter your postfix expression to be evaluated: ");
    scanf("%s",po);
    s.size=strlen(po);
    
    for (i=0;i<s.size;i++)
    {
        ch = po[i];
        switch(ch)
        {
            case '0':
            case '1':
            case '2':
            case '3':
            case '4':
            case '5':
            case '6':
            case '7':
            case '8':
            case '9':
                num=ch-'0';
                push(num);
                break;

            case '+':
                y = pop();
                x = pop();
                res = x+y;
                push(res);
                break;

            case '-':
                y = pop();
                x = pop();
                res = x-y;
                push(res);
                break;

            case '*':
                y = pop();
                x= pop();
                res = x*y;
                push(res);
                break;

            case '^':
                y = pop();
                x= pop();
                res = pow(x,y);
                push(res);
                break;

            case '/':
                y = pop();
                x= pop();
                res = x/y;
                push(res);
                break;

        }
    }
    
    result = pop();

    printf("%d",result);

}
