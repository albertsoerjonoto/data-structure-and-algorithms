/*PROGRAM QUEUE*/

#include <stdio.h>
#define SIZE 40

/*Variable Declaration*/
int r,f,i,val;
int data[SIZE+1];

/*Function Declaration*/
void queue_init(void);
int empty(void);
void enqueue(int);
void dequeue(void);
int front(void);

/*Main Program*/
void main()
{
    queue_init();
    for (i=1;i<=SIZE;i++)
    {
        printf("\n Input data queue no. %d   : ",i);
        scanf("%d",&val);
        if (val>0)
            enqueue(val);
        else if (val<0)
            if (r!=-1)
                printf("\n %d \n",front());
            else
                printf("\n Error - Queue is empty\n");
        else if (val==0)
            if (r!=-1)
                dequeue();
            else
                printf("\n Error - Queue is empty\n");
    }
}

void queue_init()
{
    r=f=-1;
}

int empty()
{
    return r==-1;
}

void enqueue(val)
{
    if(empty())
        r=f=0;
    else{
        r=r+1;
        if(r==SIZE)
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
        if (f==SIZE)
            f=0;
    }
}

int front()
{
    return data[f];
}
