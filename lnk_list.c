/*
Step1:Start
Step2: Create the structure definition of a node that contains data as integer and ptr as self referential structure pointer
Step3: Create and allocate a memory location for the structure nodes first, second, third, and fourth and temp;
Step5: Initialize root as first
Step6: Enter the data in all the nodes
step7: Print "Before Deleting" and display data and the address contents of all the nodes, also display the address of the node itself
step8: Display 1. Delete node at the beginning
                2. Delete a node at the middle
                 3. Delete node at the end
Step9: Enter Choice
Step10: if Choice=1:root=second
                    first=NULL

        if Choice=2:Enter ns (node select) for middle node
                    if ns=2:first->ptr=third
                            second=NULL
                    if ns=3:second->ptr=fourth;
                            third=NULL
                    else: Invalid Choice

        if Choice=3:third->ptr=NULL
                    fourth=NULL

Step11: Print "After Deleting" then Display the data and the address contents of all the nodes, also display the address of the node itself
Step12: Stop

*/
#include<stdio.h>
#include<stdlib.h>
struct node

{
    int data;
    struct node *ptr;
};
int main()
{
    struct node *root;
    struct node *first = (struct node*)malloc(sizeof(struct node));
    struct node *second = (struct node*)malloc(sizeof(struct node));
    struct node *third = (struct node*)malloc(sizeof(struct node));
    struct node *fourth= (struct node*)malloc(sizeof(struct node));
    struct node *tmp;

    int i;
    int choice;
    int delNodeNo;
    int ns;
    root = first;

    printf("\nEnter data in node no. 1: ");
    scanf("%d",&first->data);
    printf("Enter data in node no. 2: ");
    scanf("%d",&second->data);
    printf("Enter data in node no. 3: ");
    scanf("%d",&third->data);
    printf("Enter data in node no. 4: ");
    scanf("%d",&fourth->data);

    first->ptr = second;
    second->ptr = third;
    third->ptr = fourth;
    fourth->ptr = NULL;

    printf("\n___________________________________________________________________________\n");
    printf("\nBefore Deleting:");
    printf("\nNode\tData\tAddress inside the Node\t\tAddress of the Node");
    i=0;
    if(root == NULL)
    {
        printf(" List is empty.");
    }
    else
    {
        tmp = root;
        while(tmp != NULL)
        {
            printf("\n%d\t%d\t%p\t\t\t%p", i+1,tmp->data,tmp->ptr,tmp);       // prints the data of current node
            tmp = tmp->ptr;
            i++;                   // advances the position of current node
        }
    }

    printf("\n___________________________________________________________________________\n");
    printf("\n\nNow what do you want to do ?\n");
    printf("\n1. Delete node at the beginning\n2. Delete a node from the beginning\n3. Delete node at the end");
    printf("\nEnter Choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        root=second;
        first=NULL;
        delNodeNo=1;
        break;
    case 2:
        printf("\nWhich middle node do you want to delete? 2 or 3 : ");
        scanf("%d",&ns);
        switch(ns)
        {
        case 2:
            first->ptr=third;
            second=NULL;
            delNodeNo=2;
            break;
        case 3:
            second->ptr=fourth;
            third=NULL;
            delNodeNo=3;
            break;
        default:
            printf("!!!INVALID CHOICE!!!");
            exit(0);
        }
        break;
    case 3:
        third->ptr=NULL;
        fourth=NULL;
        break;
    default:
        printf("!!!INVALID CHOICE!!!");
        exit(0);
    }
    printf("\n___________________________________________________________________________\n");
    printf("\nAfter Deleting:");
    printf("\nNode\tData\tAddress inside the Node\t\tAddress of the Node");
    i=0;
    if(root == NULL)
    {
        printf(" List is empty.");
    }
    else
    {
        tmp = root;
        while(tmp != NULL)
        {
            if((i+1)==delNodeNo)
                i++;
            printf("\n%d\t%d\t%p\t\t\t%p", i+1,tmp->data,tmp->ptr,tmp);
            tmp = tmp->ptr;
            i++;
        }
    }
    printf("\n\n---------------------------------Thank You--------------------------------------\n\n");
    return 0;
}
