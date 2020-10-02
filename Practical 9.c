/*************************************************************************
NAME: CANDIDA RUTH NORONHA
CLASS: SE COMPS B
ROLL NO. : 8960
TITLE:  Program to create a binary tree and to perform the following operations:
	1. Insertion (Non recursive)
	2. Deletion ( Non recursive)
	3. Inorder(Recursive)
	4. Preorder (Recursive)
	5. Postorder (Recursive)
	6. Find minimum (Non Recursive)
	7. Find Maximum(Non Recursive)
	8. Search (Iterative)
	9. Search ( Recursive)
	10. Count total nodes (Recursive)
	11. Count leaf nodes (Recursive)
	12. Calculate height (Recursive)
	13. Mirror(Recursive)
SUBMISSION DATE : 02nd October, 2020
*************************************************************************/

#include<stdio.h>
#include<stdlib.h>
struct tnode
{
    int data;
    struct tnode *left,*right;
};
typedef struct
{
    struct tnode *root;
}Tree;

void insert(Tree *tr,int x)//insert into tree a new node with data x
{ //it is always inserted as a leaf node
    struct tnode *p,*prev;
    prev=NULL;
    p=(struct tnode *)malloc(sizeof(struct tnode)); //new node created
    p->data=x;
    p->left=p->right=NULL; //leaf node
    if(tr->root == NULL) //if tree is empty
    {

    tr->root=p; //newly created node becomes root

    }
    else

    {

    struct tnode *q=tr->root;
    while(q!=NULL) // if node is there
    {
    prev=q; //make that node as parent
    if(p->data < q->data) //update q
    q=q->left;
    else
    q=q->right;
    }
    //a new node p is inserted after prev node
    if(p->data >= prev->data)
        prev->right=p; //if data is greater in p, attach p as parent's(prev) right son
    else
        prev->left=p;//if data is smaller in p, attach p as parent's(prev) left son

    }

}

void delete(Tree *tr,int x)
{

    struct tnode *p,*q,*prev,*r;
    prev=NULL; //root node doesn't have parent
    p=tr->root; //start from root node
    while(p!=NULL) //search the data x
    {

        if(p->data==x)
        break;
        prev=p; //keep track of parent of p
        if(x < p->data)
            p=p->left;
        else
            p=p->right;

    }
    if(p==NULL)

    printf("Data not found\n");

    else
    {

    if( p->left == NULL || p->right == NULL) //case 1 or case 2
        q = p; //q is node to be deleted
    else //case 3
    {
        prev = p; //inorder successor parent
        q = p->right; //currently right son is inorder sucessor
        while ( q->left != NULL) // if le? son present
        {
            prev = q; //parent of r
            q= q->left;
        }
    p->data = q->data; //copy q node data to p node data
    }
    //in the following part, q node is deleted
    //q is replaced by node r
    if( q->left == NULL) //in case 1, r is NULL
        r = q->right;
    else
        r = q->left;
    if(prev==NULL) // q is root node, then no parent to it
        tr->root = r; //root is r
    else if(prev->left==q) //q is left son of its parent, r becomes left son replacing q
        prev->left = r;
    else //q is right son of its parent, r becomes right son replacing q
        prev->right = r;
    free(q);
    printf("\n Data deleted\n");

    }

}

void inorder(struct tnode *rt)
{
    if(rt!=NULL)
    {
        inorder(rt->left);
        printf(" %d\t",rt->data);
        inorder(rt->right);
    }
}

void preorder(struct tnode *rt)
{
    if(rt!=NULL)
    {
        printf(" %d\t",rt->data);
        preorder(rt->left);
        preorder(rt->right);
    }
}

void postorder(struct tnode *rt)
{
    if(rt!=NULL)
    {
        postorder(rt->left);
        postorder(rt->right);
        printf(" %d\t",rt->data);
    }
}

struct tnode * tree_minimum(struct tnode *rt)
{

    while( rt->left != NULL) //if left son present
    {
        rt = rt->left; //go to that left son
    }
    return rt; //left most node reached
}

struct tnode * tree_maximum(struct tnode *rt)
{
    while( rt->right != NULL)//if right son present
    {
        rt = rt->right;
    }
    return rt; // right most node has largest data, return its address
}

struct node * iterative_tree_search(struct tnode *rt, int key)
{

    while( rt != NULL) //if node exist
    {

        if ( key == rt->data) //compare for equality
            return rt; //if found, return node's address
        else if (key < rt->data) //if not found and key is less than node's data, go to left subtree
            rt = rt->left;
        else //if not found and key is greater than node's data, go to right subtree
            rt = rt->right;
    }
    return rt; // if key not found then this statement is reachable, and return NULL
}

struct tnode * tree_search(struct tnode *rt, int key)
{
    if (rt == NULL) //if no node in a tree return NULL
        return NULL;
    else if( key == rt->data) // if matches, return address of that node
        return rt;
    else if (key < rt->data) //if key is less than node's data then go search in left subtree
        return(tree_search(rt->left,key));
    else
    return(tree_search(rt->right,key));//if key is greater than node's data then go search in right subtree
}



int countnodes(struct tnode *rt)
{
    if( rt == NULL) //if no nodes in tree, return count as 0
        return 0;
    else //otherwise
    {
        return( 1+ countnodes(rt->left)+countnodes(rt->right)); //count the node + nodes in Left subtree+ nodes in Right Subtree
    }
}

int countleafnodes(struct tnode *rt)
{

    if (rt == NULL) //if no nodes in tree, return 0
        return 0;
    else if(rt->left == NULL && rt->right == NULL) //if leaf node, count it's occurrence, therefore return 1
        return 1;
    else
    {
        return(countleafnodes(rt->left)+countleafnodes(rt->right)); //if non-leaf node, count leaf nodes in left subtree + count nodes in Right subtree
    }
}

int height(struct tnode *rt)
{

    int lh,rh;
    if(rt==NULL) //empty tree has height -1
        return -1;
    else if(rt->left == NULL && rt->right == NULL) //leaf node is at height 0
        return 0;
    else //for non-leaf node
    {
        lh=height(rt->left); //calculate height of left subtree
        rh=height(rt->right); //calculate height of right subtree
        if(lh > rh) //since a parent is always one level above than its child level
            return lh+1; //add 1 to largest height
        else
            return rh+1;
    }
}


void mirrorImage(struct tnode *rt)
{
     struct tnode *temp;
     if(rt != NULL)
     {
         mirrorImage(rt->left);
         mirrorImage(rt->right);
         temp = rt->left;
         rt->left = rt->right;
         rt->right = temp;
         printf("%d\t",rt->data);
     }
}

int main()
{

    Tree t1; //tree t1 is created
    t1.root=NULL;//initially tree is empty
    struct tnode *ptr;
    int choice,ele;

    printf("----------------------------------------------MENU----------------------------------------------\n");
    printf(" 1.Add an element in the binary tree\n");
    printf(" 2.Delete an element in the binary tree\n");
    printf(" 3.Display in inorder fashion\n");
    printf(" 4.Display in preorder fashion\n");
    printf(" 5.Display in postorder fashion\n");
    printf(" 6.Display the smallest element in the binary tree\n");
    printf(" 7.Display the largest element in the binary tree\n");
    printf(" 8. Search for an element in the tree iteratively\n");
    printf(" 9. Search for an element in the tree recursively\n");
    printf(" 10.Count number of nodes\n");
    printf(" 11.Count the number of leaf nodes\n");
    printf(" 12.Calculate height of the binary tree\n");
    printf(" 13.Display the mirror image of the binary tree\n");
    printf(" 14.Exit\n");
    printf("------------------------------------------------------------------------------------------------\n");
    printf(" Enter the option : ");
    scanf("%d",&choice);
    printf("\n------------------------------------------------------------------------------------------------\n");
    do
    {
    switch(choice)
    {
        case 1:
            printf(" Enter the element to be added to the binary tree : ");
            scanf("%d",&ele);
            insert(&t1,ele);
            printf("\n The element %d is inserted\n",ele);
            break;

        case 2:
            printf(" Enter the element to be deleted from binary tree : ");
            scanf("%d",&ele);
            delete(&t1,ele);
            break;

        case 3:
            printf(" The numbers in the inorder fashion are : ");
            inorder(t1.root);
            printf("\n");
            break;

        case 4:
            printf(" The numbers in the preorder fashion are : ");
            preorder(t1.root);
            printf("\n");
            break;

        case 5:
            printf(" The numbers in the postorder fashion are : ");
            postorder(t1.root);
            printf("\n");
            break;

        case 6:
            ptr = tree_minimum(t1.root);
            printf(" The smallest element in the tree is : %d\n",ptr->data);
            break;

        case 7:
            ptr = tree_maximum(t1.root);
            printf(" The largest element in the tree is : %d\n",ptr->data);
            break;

        case 8:
            printf(" Enter the element to be searched iteratively : ");
            scanf("%d",&ele);
            ptr=iterative_tree_search(t1.root,ele);
            printf(" The position is : %p\n",ptr);
            break;

        case 9:
            printf("\n Enter the element to be searched recursively : ");
            scanf("%d",&ele);
            ptr=tree_search(t1.root,ele);
            printf(" The position is : %p\n",ptr);
            break;


        case 10:
            printf(" The Number of nodes in the tree are %d\n",countnodes(t1.root));
            break;

        case 11:
            printf(" The Number of leaf nodes in the tree are %d\n",countleafnodes(t1.root));
            break;

        case 12:
            printf(" The Height of the tree is %d\n",height(t1.root));
            break;

        case 13:
            printf(" The mirror image of the binary tree is : ");
            mirrorImage(t1.root);
            printf("\n");
            break;

        case 14:
            exit(0);
            break;
        }
        printf("------------------------------------------------------------------------------------------------\n");
        printf(" Enter the option : ");
        scanf("%d",&choice);
        printf("------------------------------------------------------------------------------------------------\n");

    }while(choice!=14);
    return 0;

}

/*************************************************************************
OUTPUT:
----------------------------------------------MENU----------------------------------------------
 1.Add an element in the binary tree
 2.Delete an element in the binary tree
 3.Display in inorder fashion
 4.Display in preorder fashion
 5.Display in postorder fashion
 6.Display the smallest element in the binary tree
 7.Display the largest element in the binary tree
 8.Search for an element in the tree iteratively
 9.Search for an element in the tree recursively
 10.Count number of nodes
 11.Count the number of leaf nodes
 12.Calculate height of the binary tree
 13.Display the mirror image of the binary tree
 14.Exit
------------------------------------------------------------------------------------------------
 Enter the option : 1

------------------------------------------------------------------------------------------------
 Enter the element to be added to the binary tree : 1

 The element 1 is inserted
------------------------------------------------------------------------------------------------
 Enter the option : 1
------------------------------------------------------------------------------------------------
 Enter the element to be added to the binary tree : 2

 The element 2 is inserted
------------------------------------------------------------------------------------------------
 Enter the option : 1
------------------------------------------------------------------------------------------------
 Enter the element to be added to the binary tree : 3

 The element 3 is inserted
------------------------------------------------------------------------------------------------
 Enter the option : 1
------------------------------------------------------------------------------------------------
 Enter the element to be added to the binary tree : 4

 The element 4 is inserted
------------------------------------------------------------------------------------------------
 Enter the option : 1
------------------------------------------------------------------------------------------------
 Enter the element to be added to the binary tree : 5

 The element 5 is inserted
------------------------------------------------------------------------------------------------
 Enter the option : 1
------------------------------------------------------------------------------------------------
 Enter the element to be added to the binary tree : 6

 The element 6 is inserted
------------------------------------------------------------------------------------------------
 Enter the option : 2
------------------------------------------------------------------------------------------------
 Enter the element to be deleted from binary tree : 6

 Data deleted
------------------------------------------------------------------------------------------------
 Enter the option : 3
------------------------------------------------------------------------------------------------
 The numbers in the inorder fashion are :  1     2       3       4       5
------------------------------------------------------------------------------------------------
 Enter the option : 4
------------------------------------------------------------------------------------------------
 The numbers in the preorder fashion are :  1    2       3       4       5
------------------------------------------------------------------------------------------------
 Enter the option : 5
------------------------------------------------------------------------------------------------
 The numbers in the postorder fashion are :  5   4       3       2       1
------------------------------------------------------------------------------------------------
 Enter the option : 6
------------------------------------------------------------------------------------------------
 The smallest element in the tree is : 1
------------------------------------------------------------------------------------------------
 Enter the option : 7
------------------------------------------------------------------------------------------------
 The largest element in the tree is : 5
------------------------------------------------------------------------------------------------
 Enter the option : 8
------------------------------------------------------------------------------------------------
 Enter the element to be searched iteratively : 3
 The position is : 00BE0D90
------------------------------------------------------------------------------------------------
 Enter the option : 9
------------------------------------------------------------------------------------------------

 Enter the element to be searched recursively : 3
 The position is : 00BE0D90
------------------------------------------------------------------------------------------------
 Enter the option : 10
------------------------------------------------------------------------------------------------
 The Number of nodes in the tree are 5
------------------------------------------------------------------------------------------------
 Enter the option : 11
------------------------------------------------------------------------------------------------
 The Number of leaf nodes in the tree are 1
------------------------------------------------------------------------------------------------
 Enter the option : 12
------------------------------------------------------------------------------------------------
 The Height of the tree is 4
------------------------------------------------------------------------------------------------
 Enter the option : 13
------------------------------------------------------------------------------------------------
 The mirror image of the binary tree is : 5     4       3       2       1
------------------------------------------------------------------------------------------------
 Enter the option : 14
------------------------------------------------------------------------------------------------

Process returned 0
*************************************************************************/
