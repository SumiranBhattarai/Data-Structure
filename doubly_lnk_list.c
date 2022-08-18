/*
Step1: Start
step2: initialize a structure node
step3: create structure variable newnode,root,last,temp
step4: enter no of nodes as n
step5: i=0, till i<n-1
        create memory for newnode
        Enter newnode->data
        temp->next=newnode
        newnode->prev=temp
        temp=newnode
        i++;
step6: last=temp, last->next=root
step7: display the node list
step8: create newnode again and insert data
step9: Enter location to insert the new node 1.First 2.Anywhere in the Middle 3.Last

step10: case 1:
            root->prev=newnode
            newnode->next=root
            newnode->prev=NULL
            root=newnode;
        case 2:
            enter ns
            loop and goto the next node till ns-, then
            dummy=temp
            dummy=dummy->next
            newnode->prev=temp
            newnode->next=temp->next
            temp->next=newnode
            dummy->prev=newnode
        case 3:
            last->next=newnode
            newnode->prev=last
            last=newnode
            last->next=NULL

step11 : If user wants to traverse the nodes enter choice
        temp=root;
        case 1: Traverse previous node (temp=temp->prev)
        Case 2: Traverse next node (temp=temp->next)
        case 3: Exit

step12: Display node list
step13: Stop
*/
#include<stdio.h>
#include<stdlib.h>
void insNode(int);
void display(int);
void traverse(int);

struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

struct node *temp;
struct node *dummy;
struct node *newnode;
struct node *last;
struct node *root;

int main()
{

    int n,i,choice;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("\n--------------Doubly Link List---------------");
    printf("\nHow many nodes do you want?: ");
    scanf("%d",&n);
    printf("\nEnter data in node 1: ");
    scanf("%d",&temp->data);
    temp->prev=NULL;
    root=temp;
    i=0;
    while(i<n-1)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data in node %d: ",i+2);
        scanf("%d",&newnode->data);
        temp->next=newnode;
        newnode->prev=temp;
        temp=newnode;
        i++;
    }
    last=temp;
    last->next=NULL;
    display(n);
    insNode(n);
    traverse(n);
    printf("\n\n\n---------------Thank You for using this program---------------");
    return 0;
}


void insNode(int n)
{
    int i;
    int choice=1,ns;
    int ch=1;
    while(ch==1)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("\n---------------Insert A Node---------------");
        printf("\nEnter data in new node: ");
        scanf("%d",&newnode->data);
        printf("\n---------------Specify Inserting Position---------------");
        printf("\n1.First\n2.In any given Middle position\n3.Last\nChoice: ");
        scanf("%d",&choice);
        switch(choice)
        {
        case 1:
            root->prev=newnode;
            newnode->next=root;
            newnode->prev=NULL;
            root=newnode;
            break;
        case 2:
            printf("\nWhere do you want to place your new node?");
            printf("\nChoose a node between 2 to %d: ",n-1);
            scanf("%d",&ns);
            i=0;
            if((ns>=2)&&(ns<=n-1))
            {
                temp=root;
                while(i<ns-2)
                {
                    temp=temp->next;
                    i++;
                }
                dummy=temp;
                dummy=dummy->next;
                newnode->prev=temp;
                newnode->next=temp->next;
                temp->next=newnode;
                dummy->prev=newnode;
            }
            else
                {
    printf("\n!!!Invalid Choice!!!");
    exit(0);
}
            break;
        case 3:
            last->next=newnode;
            newnode->prev=last;
            last=newnode;
            last->next=NULL;
            break;
        default:
            {
    printf("\n!!!Invalid Choice!!!");
    exit(0);
}
        }
        printf("\n---------------Node %d successfully Inserted---------------",ns);
        display(n);
        printf("\nInsert Again (1)? or Exit (0) ?: ");
        scanf("%d",&ch);
        n++;
    }
}
void display(int n)
{
    int i=0;
    int node=0;
    printf("\n\tNode\tData\t<--Previous\tNode Address\t-->Next");
    temp = root;
    while(temp!=NULL)
    {
        if(temp->prev==NULL)
            printf("\n\t%d\t%d\t%p\t\t%p\t%p", node+1,temp->data,(void *)temp->prev,(void *)temp,(void *)temp->next);
        else
            printf("\n\t%d\t%d\t%p\t%p\t%p", node+1,temp->data,(void *)temp->prev,(void *)temp,(void *)temp->next);
        temp = temp->next;
        i++;
        node++;
    }
}

void traverse(int n)
{
    int choice;
    int sel;
    int node=1;
    printf("\nTraverse the node (1) ?: ");
    scanf("%d",&choice);
    if(choice==1)
    {
        temp=root;
        printf("\nCurrent Node");
        printf("\n\tNode\tData\t<--Previous\tNode Address\t-->Next");
        printf("\n\t%d\t%d\t%p\t%p\t%p", node+1,temp->data,(void *)temp->prev,(void *)temp,(void *)temp->next);
        while(1)
        {
            printf("\nTraverse Previous node (1) or Next node (2) or exit (3)?: ");
            scanf("%d",&sel);
            switch(sel)
            {

            case 1:
                if(temp->prev==NULL)
                {
                    printf("\nPrevious Node not Found (NULL)");
                }
                else
                {
                    temp=temp->prev;
                    node--;
                    printf("\n\tNode\tData\t<--Previous\tNode Address\t-->Next");
                    printf("\n\t%d\t%d\t%p\t%p\t%p", node+1,temp->data,(void *)temp->prev,(void *)temp,(void *)temp->next);
                }
                break;
            case 2:
                if(temp->next==NULL)
                {
                    printf("\nNext Node not Found (NULL)");
                }
                else
                {
                    temp=temp->next;
                    node++;
                    printf("\n\tNode\tData\t<--Previous\tNode Address\t-->Next");
                    printf("\n\t%d\t%d\t%p\t%p\t%p", node+1,temp->data,(void *)temp->prev,(void *)temp,(void *)temp->next);
                }
                break;
            case 3:
                exit(0);
                break;
            default:
                printf("\nInvalid Choice: ");
                printf("\nEnter 0 to quit or any key to continue: ");
                scanf("%d",&choice);
                if(choice==0)
                    exit(0);
                else
                    continue;
            }
        }
    }
}

