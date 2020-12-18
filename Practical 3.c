/**********************************************************************************************************
NAME: CANDIDA RUTH NORONHA
CLASS: SE COMPS B
ROLL NO. : 8960
BATCH: C
TITLE:  Program to create Queue of Students taking admission in Fr. CRCE using static memory allocation.
SUBMISSION DATE : 12th August, 2020
**********************************************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define SIZE 20

typedef struct
{
    int reg_no;
    char branch[SIZE];
}student;

//Nested Structure
typedef struct
{
    student s[SIZE];//queue of students
    int rear,front;
}queue;

void enqueue(queue *p,int x,char *n)  //to insert elements
{
    if(p->rear==SIZE-1)
		printf("Queue is Full\n");
    else
	{
		p->rear++;
		p->s[p->rear].reg_no=x;   //inserted registration no
		strcpy(p->s[p->rear].branch,n);//inserted branch

		if(p->front==-1)
			p->front=0;
	 }
}

student dequeue(queue *p)
{
    student x;
	if(p->front==-1)
	{
	   printf("Queue is Empty\n");
	   x.reg_no=0;
	   strcpy(x.branch,"null");
	   return x;
	}
	else
	{
		x.reg_no=p->s[p->front].reg_no;
		strcpy(x.branch,p->s[p->front].branch);
		if(p->front==p->rear)
		{
		   p->front=-1;
		   p->rear=p->front;
		}
		else
			p->front++;

		return x;
	}
}

void display(queue q)
{
	int i;
    if(! isempty(q))//if queue is not empty,equivalent condition is isempty(q)==0
    {
        for(i=q.front;i<=q.rear;i++)
        {
           printf("Student %d :\nRegistration number: %d\nBranch: %s\n",i+1,q.s[i].reg_no,q.s[i].branch);
        }

    }
    else
    {
		printf("Queue is Empty");
    }
}

int isempty(queue q)
{
    if(q.front==-1)
		return 1;
    else
		return 0;
}

int main()
{
	queue q1;
	student y;
	int i,choice;
	char ch;

	q1.front=q1.rear=-1;


	do
	{
		printf("Enter the choice: 1.Enqueue 2.Dequeue 3.Display\n");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter the Student's Registration number:\n");
				scanf("%d",&y.reg_no);
				printf("Enter the Student's branch:\n");
				scanf("%s",y.branch);

				enqueue(&q1,y.reg_no,y.branch);
				break;

			case 2 :
				y=dequeue(&q1);
				printf("Turn of the following student to submit the form:\n%d and %s \n",y.reg_no,y.branch);
				break;

			case 3:
				printf("Students who have not submitted the form:\n");
				display(q1);
				break;

			default: printf("Enter proper choice:\n");

		}
	    printf("Do you want to continue:\n");
	    scanf("%s",&ch);
	    printf("\n\n");
		
    }while(ch=='y'||ch=='Y');

    return 0;
}
/**********************************************************************************************************
OUTPUT:

Enter the choice: 1.Enqueue 2.Dequeue 3.Display
1
Enter the Student's Registration number:
8960
Enter the Student's branch:
Computer
Do you want to continue:
y


Enter the choice: 1.Enqueue 2.Dequeue 3.Display
1
Enter the Student's Registration number:
8942
Enter the Student's branch:
Mechanical
Do you want to continue:
y


Enter the choice: 1.Enqueue 2.Dequeue 3.Display
1
Enter the Student's Registration number:
9000
Enter the Student's branch:
Production
Do you want to continue:
y


Enter the choice: 1.Enqueue 2.Dequeue 3.Display
2
Turn of the following student to submit the form:
8960 and Computer
Do you want to continue:
y


Enter the choice: 1.Enqueue 2.Dequeue 3.Display
3
Students who have not submitted the form:
Student 2 :
Registration number: 8942
Branch: Mechanical
Student 3 :
Registration number: 9000
Branch: Production
Do you want to continue:
n
Process returned 0
**********************************************************************************************************/
