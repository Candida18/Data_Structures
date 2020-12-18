/*********************************************************************************
TITLE: Program to implement Topological Sorting.
*********************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#define S 50

//Queue is created
typedef struct
{
    int a[S];
    int front, rear;
}Queue;

//Graph is created
typedef struct
{
    int adj[S][S];
    int e,v;
}Graph;

//isEmpty function
int isEmpty(int front)
{
    if(front==-1)
        return 1;
    else
        return 0;
}

//Dequeue function
int dequeue(Queue *q)
{
    int x=q->a[q->front];
    if(q->front==q->rear)
    {
        q->front=q->rear=-1;
    }
    else
     {
         q->front++;
     }
    return x;
}

//Enqueue function
void enqueue(Queue *q, int e)
{
    q->rear++;
    q->a[q->rear]=e;
    if(q->front==-1)
    {
        q->front=0;
    }
}

//initializing graph
void intializeGraph(Graph *g)
{
    for(int i=0;i<g->v;i++)
    {
        for(int j=0;j<g->v;j++)
        {
            g->adj[i][j]=0;
        }

    }
}

//Add elements into the graph using adj matrix
void add(Graph *g, int src, int dest)
{
    g->adj[src][dest]=1;
    //g->adj[dest][src]=0; //for undirected graph
}

//Topological Order using queue data structure
void topologicalOrder(Graph g, Queue *t)
{
    int indegree[g.v],i;
    for( i=0;i<g.v;i++)
     {
         indegree[i]=0;

        for(int j=0;j<g.v;j++)
        {
            indegree[i]=indegree[i]+g.adj[j][i];
        }
     }

    for(int i=0;i<g.v;i++)
    {
        if(indegree[i]==0)
        {
            enqueue(t,i);
        }
    }

    while(!isEmpty(t->front))
    {
        int x=dequeue(t);
        printf("%d ",x);

        indegree[x]=-1;
        for(int k=0;k<g.v;k++)
        {
            if(g.adj[x][k]==1)
            {
                indegree[k]=indegree[k]-1;
                if(indegree[k]==0)
                {
                    enqueue(t,k);
                }
            }
        }
    }
}


void printadjmatrix(Graph g)
{
    for(int i=0;i<g.v;i++)
    {
        for(int j=0;j<g.v;j++)
        {
            printf("%d ",g.adj[i][j]);

        }
        printf("\n");
    }
}


int main()
{
    //Initializing different data structures
    Graph g;
    Queue t;
    t.front=t.rear=-1;
    int src,dest;

    //Inputing the no. of vertices
    printf("\nEnter the no. of vertices for directed graph : ");
    scanf("%d",&g.v);

    //Inputing the no. of edges
    printf("\nEnter the no. of edges for directed graph : ");
    scanf("%d",&g.e);

    //Initializing graph
    intializeGraph(&g);
    //Entering the source code & destination code
    for(int i=1;i<=g.e;i++)
    {
        printf("\nEnter the source node value : ");
        scanf("%d",&src);
        printf("\nEnter the destination node value : ");
        scanf("%d",&dest);
        add(&g,src,dest); //Adding elements into the graph
    }
    printf("\n***** Adjacency Matrix *****\n");
    printadjmatrix(g);
    printf("\n***** Topological Sort *****\n");
    topologicalOrder(g,&t);
    return 0;
}
/*********************************************************************************
OUTPUT:
Enter the no. of vertices for directed graph : 7

Enter the no. of edges for directed graph : 8

Enter the source node value : 1

Enter the destination node value : 2

Enter the source node value : 2

Enter the destination node value : 3

Enter the source node value : 2

Enter the destination node value : 5

Enter the source node value : 2

Enter the destination node value : 4

Enter the source node value : 3

Enter the destination node value : 5

Enter the source node value : 4

Enter the destination node value : 5

Enter the source node value : 5

Enter the destination node value : 6

Enter the source node value : 7

Enter the destination node value : 4

***** Adjacency Matrix *****
0 0 0 0 0 0 0
0 0 1 0 0 0 0
0 0 0 1 1 1 0
0 0 0 0 0 1 0
0 0 0 0 0 1 0
0 0 0 0 0 0 1
0 0 0 0 0 0 0

***** Topological Sort *****
0 1 2 3 4 5 6
Process returned 0
*********************************************************************************/
