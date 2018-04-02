#include <stdio.h>
#define maxV 7

void dfs(int,int);
void print_graph(void);
void sequence(void);

int count=0;
int x,y,v,w,comp=1,number;
char seq;

int G[maxV][maxV]= {{0,1,1,0,0,0,0},{1,0,1,0,0,0,0},{1,1,0,1,0,0,0},{0,0,1,0,0,0,0},{0,0,0,0,0,1,1},{0,0,0,0,1,0,1},{0,0,0,0,1,1,0}};
int visit[maxV]={0,0,0,0,0,0,0};
int component[maxV]={0,0,0,0,0,0,0};

int main(void)
{
    //JUST TO PRINT THE GRAPH
    printf("The Graph 'G'\n");
    print_graph();
    printf("\n");

    //MAKE SURE ALL VERTICES HAVE ALREADY BEEN VISITED
    for (v=0;v<=(maxV-1);v++)
    {
        if (visit[v]==0)
        {
            //A NEW COMPONENT (IF V IS MARKED 0)
            printf("\nComponent-%d:\n",comp);
            comp=comp+1;

            //RECURSIVELY DO DFS, NUMBER MEANS INDEX OF VERTICES IN THIS COMPONENT
            number=0;
            dfs(v,number);

            //PRINT THE VERTICES
            printf("Vertices in this component: ");
            for (number=0;number<=maxV;number++)
            {
                if (component[number]!=0)
                    printf("%d ",component[number]);
            }
            printf("\n");

            //INITIALIZE THE VERTICES FOR THE NEXT COMPONENT
            for (number=0;number<=maxV;number++)
            {
                component[number]=0;
            }
            printf("\n");
        }
    }

    //PRINT FINAL SEQUENCE OF VERTICES BEING VISITED
    printf("\nSequence of vertices being visited [1,2,3,4,5,6,7]:\n");
    for (v=0;v<=(maxV-1);v++)
    {
        printf("%d ",visit[v]);
    }
    printf("\n");

}

void dfs(int v,int number)
{
    //TO ASSIGN FINAL SEQUENCE OF VERTICES BEING VISITED
    count = count+1;
    visit[v] = count;

    //TO LIST THE VERTICES IN THIS COMPONENT
    component[number]=v+1;
    number=number+1;

    //TO VISIT ADJACENT VERTICES
    for (w=0;w<=(maxV-1);w++)
    {
        if (G[v][w]==1)
        {
            if (visit[w]==0)
            {
                printf("Parent of %d is %d\n",w+1,v+1);
                dfs(w,number);
            }
        }
    }
}

//JUST TO PRINT THE GRAPH
void print_graph(void)
{
    for (x=0;x<=maxV-1;x++)
    {
        for (y=0;y<=maxV-1;y++)
        {
            printf("G[%d][%d]= %d ",x+1,y+1,G[x][y]);
        }
        printf("\n");
    }
}
