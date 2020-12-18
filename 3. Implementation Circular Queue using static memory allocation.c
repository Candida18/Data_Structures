/*************************************************************************
NAME: CANDIDA NORONHA
CLASS: SE COMPS B
ROLL NO. : 8960
TITLE:  Program to implement Circular Queue of int using static memory allocation.
SUBMISSION DATE : 11th August, 2020
*************************************************************************/

#include<stdio.h>
#include<stdlib.h>
#define SIZE 3
typedef struct
{
int a[SIZE]; //Queue of integers
int front,rear;
}CQueue;

void cenqueue(CQueue *p,int x) //insert element in queue at rear end
{
    if (isFull(p))//if queue is full
    {
    printf("Queue Full\n"); //report Queue full message
    }
    else
    {
        p->rear = (p->rear+1) % SIZE ;//increment rear
        p->a[p->rear]=x; //put the element at rear index
        if( p->front == -1) //if first element inserted in queue
			p->front = 0;
    }
}

int cdequeue( CQueue *p)
{
    int x;
    if (isEmpty(p)) //if queue empty
    {
        printf("Queue Empty\n"); //report Queue empty message
        return -1; //return something which we are not going to store in queue
    }
    else
    {
        x=p -> a[ p->front ]; //take element at front index and store it in local variable
        if( p->front == p->rear) //last element deleted from queue
			p->front = p->rear = -1; //go back to intial postion
        else
			p->front = (p->front+1) % SIZE; //increment front
        return x; //return element
    }
}

void display(CQueue q)
{
    int i;
    if ( ! isEmpty(q) ) // equivalent to check isEmpty(q) == 0
    {
        for( i = q.front; i != q.rear; i=(i+1)%SIZE)

        {
        printf("\t%d",q.a[i]);
        }
    printf("\t%d",q.a[i]);
    }
}

//isEmpty method 
int isEmpty(CQueue q)
{
    if (q.front == -1) //initial queue
        return 1;
    else
        return 0;
}

//isFull method
int isFull(CQueue q)
{
if ((q.rear+1)%SIZE == q.front )//condition for circular queue
    return 1;
else
    return 0;
}

int main()
{
    CQueue q1;
    int x,choice;
    char ch='n';
    q1.front = q1.rear = -1;
    do
    {
        printf("Enter the choice: 1.Enqueue 2.Dequeue 3.Exit\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Enter the element to be inserted :\n");
                scanf("%d",&x);
                cenqueue(&q1,x);
                break;
            case 2:
                x = cdequeue(&q1);
                printf("The removed element is %d\n",x);
                break;
            case 3:
                printf("Queue Contents\n");
                display(q1);
                break;
            case 5:
            exit(0); //exit from program with exit status 0

        }
    printf("Do you want to continue:\n");
    scanf("%s",&ch);
    }
while(ch=='y'||ch=='Y'); 
return 0;
}
/*************************************************************************
OUTPUT:
TEST CASE 1 :
Enter the choice: 1.Enqueue 2.Dequeue 3.Exit
1
Enter the element to be inserted :
64
Do you want to continue:
y
Enter the choice: 1.Enqueue 2.Dequeue 3.Exit
1
Enter the element to be inserted :
78
Do you want to continue:
y
Enter the choice: 1.Enqueue 2.Dequeue 3.Exit
1
Enter the element to be inserted :
60
Do you want to continue:
y
Enter the choice: 1.Enqueue 2.Dequeue 3.Exit
1
Enter the element to be inserted :
40
Queue Full
Do you want to continue:
n
Process returned 0



TEST CASE 2 :
Enter the choice: 1.Enqueue 2.Dequeue 3.Exit
1
Enter the element to be inserted :
30
Do you want to continue:
y
Enter the choice: 1.Enqueue 2.Dequeue 3.Exit
1
Enter the element to be inserted :
40
Do you want to continue:
y
Enter the choice: 1.Enqueue 2.Dequeue 3.Exit
1
Enter the element to be inserted :
60
Do you want to continue:
y
Enter the choice: 1.Enqueue 2.Dequeue 3.Exit
2
The removed element is 30
Do you want to continue:
y
Enter the choice: 1.Enqueue 2.Dequeue 3.Exit
3
Queue Contents
40      60
Do you want to continue:
n
Process returned 0

*************************************************************************/


