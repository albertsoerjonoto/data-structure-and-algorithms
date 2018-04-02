#include <stdio.h>
#define SIZE 10

int v,i=1,t,val;
int data[SIZE+1];

void stack_init(void);
int empty(void);
void push(int);
void pop(void);
int top(void);
int bottom(void);

/*Bonus*/
int is_full(void);
int push_full(int);


int main()
{
    stack_init();
    do
    {
        printf("\n Data no-%d: ",i);
        scanf("\n %d",&val);
        if (val>0)
            push_full(val);
        else if (val<0)
        {
            if (!empty())
            {
                printf("\n              Top    : %d\n",top());
                printf("\n              Bottom : %d\n",bottom());
            }
            else
                printf("\n              Error - Stack is empty\n");
        }
        else if (val==0)
        {
            if (!empty())
                pop();
            else
                printf("\n              Error - Stack is empty\n");
        }

        if (is_full())
        {
            printf("\n THE STACK IS FULL\n");
        }
        i++;
    }while (val!=-999);
}

void stack_init()
{
    t=-1;
}

int empty()
{
    return (t==-1);
}

void push(int)
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

int is_full()
{
    return t==SIZE-1;
}

int push_full(int)
{
    if(is_full())
    {
        return false;
    }
    else
    {
        push(val);
        return true;
    }
}

int bottom()
{
    return data[0];
}
