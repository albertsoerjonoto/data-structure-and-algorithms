#include <stdio.h>
#define SIZE 4

int i=1,r,f,val;
int data[SIZE+1];

void queue_init(void);
int empty(void);
void enqueue(int);
void dequeue(void);
int front(void);

/*Bonus*/
int is_full(void);
int enqueue_full(int);
int rear(void);

int main()
{
    queue_init();
    do
    {
        printf("\n Data no-%d: ",i);
        scanf("\n %d",&val);
        if (val>0)
            enqueue_full(val);
        else if (val<0)
        {
            if (!empty())
            {
                printf("\n              Front : %d\n",front());
                printf("\n              Rear  : %d\n",rear());
            }
            else
                printf("\n              Error - Queue is empty\n");
        }
        else if (val==0)
        {
            if (!empty())
                dequeue();
            else
                printf("\n              Error - Queue is empty\n");
        }

        if (is_full())
        {
            printf("\n THE QUEUE IS FULL\n");
        }
        i++;
    }while (val!=-999);
}

void queue_init()
{
    r=f=-1;
}

int empty()
{
    return (r==-1);
}

void enqueue(int)
{
    if (empty())
        r=f=0;
    else{
        r=r+1;
        if (r==SIZE)
            r=0;
    }
    data[r]=val;
}

void dequeue()
{
    if(r==f)
        r=f=-1;
    else{
        f=f+1;
        if(f==SIZE)
            f=0;
    }
}

int front()
{
    return data[f];
}

int is_full()
{
    if (r==f==-1)
        return false;
    else
        return ((r-f)==SIZE-1);
}

int enqueue_full(int)
{
    if(is_full())
    {
        return false;
    }
    else
    {
        enqueue(val);
        return true;
    }
}

int rear()
{
    return data[r];
}
