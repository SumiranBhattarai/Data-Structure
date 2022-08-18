/*
Step1: Start
step2: initialize a structure node
step3: create structure variable newnode,root,last,temp
step4: enter no of nodes as n
step5: create n newnodes and insert data
step6: last=temp, last->link=root
step7: display the node list
step8: ask user to 1.Insert or 2.Delete node
step9: enter choice
step10: if choice=1 then goto function insNode
            ask user where to insert 1.First 2.In any given Middle pos 3.Last
            enter pos
                pos=1: newnode->link=last->link;
                        last->link=newnode;
                        root=newnode;

                pos=2:select any middle position as ns
                        place the newnode after ns position
                            newnode->link=temp->link;
                            temp->link=newnode;

                pos=3: newnode->link=last->link;
                        last->link=newnode;
                        last=newnode;

    step10: if choice=2 (i3. delete)
                enter delete pos 1.first 2.middle 3.last
                    pos=1:root=root->link;
                            last->link=root;

                    pos=2:enter ns (node select)
                            jump from node to node till ns-2
                            after ns-2 delete node by
                                Del=temp;
                                temp=temp->link;
                                Del->link=temp->link;
                    pos=3:jumo till n-2
                        after n-2 delete node by
                            temp->link=root;
                            last=temp;
step11: Display node list
step12: Stop




*/
#include<stdio.h>
#include<stdlib.h>
void insNode(int);
void delNode(int);
void Invalid();
void display(int,int);

struct node
{	 	  	   	   	  		  	 	
    int data;
    struct node *link;
};

struct node *temp;
struct node *newnode;
struct node *last;
struct node *root;

int main()
{
    int n,i,choice;
    temp=(struct node*)malloc(sizeof(struct node));
    printf("\n---------------Circular Link List---------------");
    printf("\nHow many nodes do you want?: ");
    scanf("%d",&n);
    printf("\nEnter data in node 1: ");
    scanf("%d",&temp->data);
    root=temp;
    i=0;
    while(i<n-1)
    {
        newnode=(struct node*)malloc(sizeof(struct node));
        printf("Enter data in node %d: ",i+2);
        scanf("%d",&newnode->data);
        temp->link=newnode;
        temp=newnode;
        i++;
    }
    last=temp;
    last->link=root;
    display(n,0);
    printf("\n\n---------------What do you want to do?---------------");
    printf("\n1.Insert a node");
    printf("\n2.Delete a node\nChoice: ");
    scanf("%d",&choice);
    switch(choice)
    {	 	  	   	   	  		  	 	
    case 1:
        insNode(n);
        break;
    case 2:
        delNode(n);
        break;
    default:
        Invalid();
    }
    printf("\n\n\n---------------Thanking for using this program---------------");
    return 0;
}


void insNode(int n)
{
    int i;
    int choice,ns; //ns (node Select)
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
        ns=1;
        newnode->link=last->link;
        last->link=newnode;
        root=newnode;
        break;
    case 2:
        printf("\nWhere do you want to place your new node?");
        printf("\nChoose a node between 2 to %d: ",n-1);
        scanf("%d",&ns);
        if((ns>=2)&&(ns<=n-1))
        {	 	  	   	   	  		  	 	
            i=0;
            temp=root;
            while(i<ns-2)
            {
                temp=temp->link;
                i++;
            }
            newnode->link=temp->link;
            temp->link=newnode;
        }
        else
            Invalid();
        break;
    case 3:
        ns=n;
        newnode->link=last->link;
        last->link=newnode;
        last=newnode;
        break;
    default:
        Invalid();
    }
    printf("\n---------------Node %d successfully Inserted---------------",ns);
    display(n,1);
}
void delNode(int n)
{
    int i;
    int choice,ns;
    struct node *Del;
    printf("\nWhich node do you want to delete?");
    printf("\n1.First node\n2.Any given Middle node\n3.Last node\nChoice: ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        ns=1;
        root=root->link;
        last->link=root;
        break;
    case 2:
        printf("\nSpecify a node between 2 to %d: ",n-1);
        scanf("%d",&ns);
        if((ns>=2)&&(ns<=n-1))
        {	 	  	   	   	  		  	 	
            i=0;
            temp=root;
            while(i<(ns-2))
            {
                temp=temp->link;
                i++;
            }
            Del=temp;
            temp=temp->link;
            Del->link=temp->link;
        }
        else
            Invalid();
        break;
    case 3:
        ns=n;
        i=0;
        temp=root;
        while(i<ns-2)
        {
            temp=temp->link;
            i++;
        }
        temp->link=root;
        last=temp;
        break;
    default:
        Invalid();
    }
    printf("\n---------------Node %d successfully Deleted and Replaced---------------",ns);
    display(n,-1);
}

void Invalid()
{
    printf("\n!!!Invalid Choice!!!");
    exit(0);
}	 	  	   	   	  		  	 	
void display(int n,int ns)
{
    int repeat;
    if(ns==1)
        {
            repeat=n*2+1;
            printf("\n\n---------------After Insertion---------------");
        }
    else if(ns==0)
        {
            printf("\n\n---------------Before Operation---------------");
            repeat=n*2-1;
        }
    else if(ns==-1)
        {
            printf("\n\n---------------After Deletion---------------");
            repeat=(n-1)*2-1;
        }
    int i=0;
    int node=0;
    printf("\n\tNode\tData\tAddress of the Node\t\tAddress inside the Node");
    temp = root;
    while(i<=repeat)
    {
        printf("\n\t%d\t%d\t%p\t\t\t%p", node+1,temp->data,temp,temp->link);       // prints the data of current node
        temp = temp->link;
        i++;
        node++;
        if(ns==1)
        {
            if(i%(n+1)==0)
            {
                printf(" <--- Points to the root node");
                node=0;
            }// advances the position of current node
        }	 	  	   	   	  		  	 	
        else if(ns==0)
        {
            if(i%n==0)
            {
                printf(" <--- Points to the root node");
                node=0;
            }
        }
        else if(ns==-1)
        {
            if(i%(n-1)==0)
            {
                node=0;
                printf(" <--- Points to the root node");
            }
        }
    }
    printf("\n..........THE CYCLE CONTINUES..........");
}

