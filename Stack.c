/*PROGRAM STACK*/

#include <stdio.h>
#define max 40

/*Variable Declaration*/
int t,i,val;
int data[max+1];

/*Function Declaration*/
void stack_init(void);
int empty(void);
void push(int);
void pop(void);
int top(void);

/*Main Program*/
void main()
{
    stack_init();
    for (i=1;i<=max;i++)
    {
        printf("\n Input data stack no. %d   : ",i);
        scanf("%d",&val);
        if (val>0)
            push(val);
        else if (val<0)
            if (t!=-1)
                printf("\n %d \n",top());
            else
                printf("\n Error - Stack is empty\n");
        else if (val==0)
            if (t!=-1)
                pop();
            else
                printf("\n Error - Stack is empty\n");
    }
}

void stack_init()
{
    t=-1;
}

int empty()
{
    return t==-1;
}

void push(val)
{
    t=t+1;
    data[t]=val;
}

void pop()
{
    t=t-1;
}

int top()
{
    return data[t];
}
