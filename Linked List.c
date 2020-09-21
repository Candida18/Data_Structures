


#include<stdio.h>
#include<stdlib.h>
typedef struct node
{

    int data; //node containing int data
    struct node *next;

}Node;
typedef struct
{

    Node *start;

}LL;

void insertbeg(LL *lptr,int x)
{

    Node *p; //create a new node
    p=(Node *)malloc(sizeof(Node));
    p->data=x;
    p->next= lptr->start; //current start node now becomes second node
    lptr->start=p; //newly created node becomes start node

}

void append(LL *lptr,int x) //insert node at end
{

    Node *p,*q;
    p=(Node *)malloc(sizeof(Node));
    p->data=x;
    p->next=NULL; //make the node as last node
    if(lptr->start==NULL) //is this a first node?
    {

        lptr->start=p;

    }
    else
    {

        q=lptr->start;
        while(q ->next!=NULL) //traverse LL until you reach the last node
        {
            q=q->next;
        }
        q->next=p; //link last node with current node

    }

}

void deletenode(LL *lptr,int x)
{

    Node *q;
     q = lptr->start;
    Node *p = NULL;
    while( q != NULL) //search the node
    {

        if (q->data == x) //data matches found, break while
        break;
        p = q; //if not found, current node becomes previous node
        q = q->next; //go to next node

    }
    if( q == NULL) //if desired node not found
    {

        printf("Node with %d data not found\n",x);

    }

    else //if found

    {

        if(lptr->start == q) //if node to be deleted is first node
        {
            lptr->start = lptr->start->next; //or write q->next
            //update start, start will now point to second node
        }
        else
        {
            p->next = q->next;//previous node points to node after node to be deleted
        }
        free(q); //release the memory being pointed by q

    }

}

int countnodes(LL l)
{

    int count=0;
    Node *ptr;
    ptr= l.start;
    while(ptr!= NULL)
    {

        count++; //increment counter if node exist
        ptr = ptr->next; //go to next node

    }
    return count;

}

void concat(LL *lptr1,LL l2)
{

    Node *q;
    if (l2.start == NULL) //l2 is empty

    return;

    if(lptr1->start==NULL) //l1 is empty and l2 is Not Empty
    {

        lptr1->start=l2.start;

    }
    else
    {

        q=lptr1->start; //locate last node of LL 1
        while(q->next != NULL)
        {
            q=q->next;
        }
        q->next=l2.start; //link last node of l1 with first node of l2

    }

}

void display(LL l)
{

    Node *q;
    q=l.start;
    while(q!=NULL) //until LL gets exhausted

    {

        printf("%d\n",q->data);
        q=q->next;

    }

}

void reverse(LL *lptr)
{

    Node *q,*r,*p;
    p=NULL; //previous nod
    q=lptr->start; //current node
    while(q!=NULL)
    {

    r=q->next; //store next node in r pointer
    q->next=p; //current node points to previous node
    p=q; //for next iteration, current node becomes previous
    q=r; //for next iteration, r node becomes current node

    }
lptr->start=p; //modify start so that it points to last node of original LL

}

void insertn(LL *lptr,int n,int x)
{
    Node *p,*q;
    p = (Node *)malloc(sizeof(Node));
    p->data = x;
    p->next = lptr->start;
    q = lptr->start;

    for(int i=1;i<=n-1;i++)
    {
        q = q->next;

    }
    p->next=q->next;
    q->next = p;

}

int main()
{

    LL l1,l2,l3; //three linked list of integers
    l1.start=NULL;
    l2.start=NULL;
    l3.start=NULL;
    int choice,ele,n;
    do
    {
        printf("===================================================================================================\n");
        printf("\nEnter your choice :\n 1.Insert at beg LL1\n 2.Insert at end\n 3.Insert after n nodes\n 4.Display\n 5.Delete Data\n 6.Count Nodes\n 7.Reverse\n 8.Concatenate 2 LL\n 9.Exit\n\n");
        printf("===================================================================================================\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 :
                printf("Enter the element to be added at the beginning of the Linked List :\n");
                scanf("%d",&ele);
                insertbeg(&l1,ele);

                break;

            case 2 :
                printf("Enter the element to be added at the end of the Linked List :\n");
                scanf("%d",&ele);
                append(&l1,ele);

                break;

            case 3 :
                printf("After how many nodes do you want to add the new node:\n");
                scanf("%d",&n);
                printf("Enter the element to be added at position %d :\n",n+1);
                scanf("%d",&ele);
                insertn(&l1,n,ele);

                break;

            case 4 :
                printf("The Linked List is :\n");

                display(l1);

                break;

            case 5 :
                printf("Enter the data to be deleted:\n");

                scanf("%d",&ele);
                deletenode(&l1,ele);

                break;

            case 6 :
                printf("The total nodes in the Linked List are : %d\n",countnodes(l1));

                break;

            case 7 :

                append(&l3,80);
                append(&l3,90);
                insertbeg(&l3,100);
                reverse(&l3);
                printf("The reversed Linked List is:\n");
                display(l3);

                break;

            case 8 :
                append(&l2,60);
                append(&l2,50);
                insertbeg(&l2,40);
                concat(&l1,l2);
                printf("The concatenated Linked List is :\n");
                display(l1);

                break;


        }

    }while (choice!=9);

    return 0;

}

/*****************************************************************************************************
OUTPUT:
===================================================================================================

Enter your choice :
 1.Insert at beg LL1
 2.Insert at end
 3.Insert after n nodes
 4.Display
 5.Delete Data
 6.Count Nodes
 7.Reverse
 8.Concatenate 2 LL
 9.Exit

===================================================================================================
1
Enter the element to be added at the beginning of the Linked List :
64
===================================================================================================

Enter your choice :
 1.Insert at beg LL1
 2.Insert at end
 3.Insert after n nodes
 4.Display
 5.Delete Data
 6.Count Nodes
 7.Reverse
 8.Concatenate 2 LL
 9.Exit

===================================================================================================
1
Enter the element to be added at the beginning of the Linked List :
78
===================================================================================================

Enter your choice :
 1.Insert at beg LL1
 2.Insert at end
 3.Insert after n nodes
 4.Display
 5.Delete Data
 6.Count Nodes
 7.Reverse
 8.Concatenate 2 LL
 9.Exit

===================================================================================================
2
Enter the element to be added at the end of the Linked List :
47
===================================================================================================

Enter your choice :
 1.Insert at beg LL1
 2.Insert at end
 3.Insert after n nodes
 4.Display
 5.Delete Data
 6.Count Nodes
 7.Reverse
 8.Concatenate 2 LL
 9.Exit

===================================================================================================
3
After how many nodes do you want to add the new node:
2
Enter the element to be added at position 3 :
25
===================================================================================================

Enter your choice :
 1.Insert at beg LL1
 2.Insert at end
 3.Insert after n nodes
 4.Display
 5.Delete Data
 6.Count Nodes
 7.Reverse
 8.Concatenate 2 LL
 9.Exit

===================================================================================================
4
The Linked List is :
78
64
25
47
===================================================================================================

Enter your choice :
 1.Insert at beg LL1
 2.Insert at end
 3.Insert after n nodes
 4.Display
 5.Delete Data
 6.Count Nodes
 7.Reverse
 8.Concatenate 2 LL
 9.Exit

===================================================================================================
5
Enter the data to be deleted:
78
===================================================================================================

Enter your choice :
 1.Insert at beg LL1
 2.Insert at end
 3.Insert after n nodes
 4.Display
 5.Delete Data
 6.Count Nodes
 7.Reverse
 8.Concatenate 2 LL
 9.Exit

===================================================================================================
4
The Linked List is :
64
25
47
===================================================================================================

Enter your choice :
 1.Insert at beg LL1
 2.Insert at end
 3.Insert after n nodes
 4.Display
 5.Delete Data
 6.Count Nodes
 7.Reverse
 8.Concatenate 2 LL
 9.Exit

===================================================================================================
6
The total nodes in the Linked List are : 3
===================================================================================================

Enter your choice :
 1.Insert at beg LL1
 2.Insert at end
 3.Insert after n nodes
 4.Display
 5.Delete Data
 6.Count Nodes
 7.Reverse
 8.Concatenate 2 LL
 9.Exit

===================================================================================================
7
The reversed Linked List is:
90
80
100
===================================================================================================

Enter your choice :
 1.Insert at beg LL1
 2.Insert at end
 3.Insert after n nodes
 4.Display
 5.Delete Data
 6.Count Nodes
 7.Reverse
 8.Concatenate 2 LL
 9.Exit

===================================================================================================
8
The concatenated Linked List is :
64
25
47
40
60
50
===================================================================================================

Enter your choice :
 1.Insert at beg LL1
 2.Insert at end
 3.Insert after n nodes
 4.Display
 5.Delete Data
 6.Count Nodes
 7.Reverse
 8.Concatenate 2 LL
 9.Exit

===================================================================================================
9

Process returned 0

*****************************************************************************************************/

