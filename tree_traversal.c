//Programmed By: Sumiran Bhattarai (202111502)
/*
step1: start
step2: create a structure node with integer data and self referential node pointer right and left
step3: create a function newnode, which inserts data and left-right node addresses in the newnode
step4: create a function preorder
        where if node==null, then return
        else
            print node data,
            call recursive function preorder(node->left)
            call recursive function preorder(node->right)

step5: create a function inorder
        where if node==null, then return
        else
            call recursive function preorder(node->left)
            print node data,
            call recursive function preorder(node->right)

step6: create a function preorder
        where if node==null, then return
        else
            call recursive function preorder(node->left)
            call recursive function preorder(node->right)
            print node data,
step7: inside main create and print the tree
step8: enter choice
step9: switch(choice)
        case 1: preorder(root);
        case 2: inorder(root);
        case 3: postorder(root);
step10: stop
*/


#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *right;
    struct node *left;
};

struct node *newnode(int data)
{
    struct node *treenode = (struct node*)malloc(sizeof(struct node));
    treenode->data=data;
    treenode->left=NULL;
    treenode->right=NULL;
    return(treenode);
}

void preorder(struct node* Node)
{
    if(Node==NULL)
        return;
    else
    {
        printf("%d ",Node->data);
        preorder(Node->left);
        preorder(Node->right);
    }
}

void inorder(struct node* Node)
{
    if(Node==NULL)
        return;
    else
    {

        inorder(Node->left);
        printf("%d ",Node->data);
        inorder(Node->right);
    }
}

void postorder(struct node* Node)
{
    if(Node==NULL)
        return;
    else
    {
        postorder(Node->left);
        postorder(Node->right);
        printf("%d ",Node->data);
    }
}


int main()
{
    int choice;
    struct node *root=newnode(10);
    printf("\n\t\t***************** TREE TRAVERSAL *****************\n\n");
    printf("\n\t\t\t ______________%d________________",root->data);
    root->left=newnode(20);
    printf("\n\t\t _______%d_______",root->left->data);
    root->right=newnode(30);
    printf("\t\t\t%d_______",root->right->data);
    root->left->left=newnode(40);
    printf("\n\t\t%d",root->left->left->data);
    root->left->right=newnode(60);
    printf("\t\t%d_______",root->left->right->data);
    root->right->left=newnode(50);
    printf("\t\t\t%d",root->right->left->data);
    root->left->right->right=newnode(70);
    printf("\n\t\t\t\t\t%d",root->left->right->right->data);
    printf("\n\nFor the above given tree which traversal algorithm do you want to apply?");
    printf("\n1.Preorder\n2.Inorder\n3.Postorder\nChoice: ");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: printf("\n\nThe Preorder Traversal of the above Tree is: ");
            preorder(root);
        break;
        case 2: printf("\n\nThe Inorder Traversal of the above Tree is: ");
            inorder(root);
        break;
        case 3: printf("\n\nThe Postorder Traversal of the above Tree is: ");
            postorder(root);
        break;
        default:
            {
                printf("\n\t\t--------!!! INVALID CHOICE !!!--------");
                exit(0);
            }
    }
    printf("\n\n\n\t**************** THANK YOU FOR USING THIS PROGRAM ****************");
    return 0;
}
