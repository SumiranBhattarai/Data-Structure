/*
 step1: Start.
 step2: create a n-node binary search tree data structure and insert element into each tree node
 step3: display preorder, inorder and postorder of the tree
 step4: display 1.Delete Leaf Node
                2.Delete a node having one child
                3.Delete node having two children
                4.Quit
 step5: enter choice
        if choice=1 then enter and delete the leaf node
            if choice=2 then enter and delete the node with one child
                if choice=2 then enter and delete the node with two children
                    if choice=4 then exit the program
 step6: stop
 */

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node *left;
    struct node *right;
};

struct node *newnode(int data)
{
    struct node *treenode = (struct node*)malloc(sizeof(struct node));
    treenode->data=data;
    treenode->left=NULL;
    treenode->right=NULL;
    return(treenode);
}

struct node *insert(struct node* Node, int data)
{
    if (Node == NULL)
        return newnode(data);

    if (data < Node->data)
        Node->left = insert(Node->left, data);
    else
        Node->right = insert(Node->right, data);

    return Node;
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

struct node* minValueNode(struct node* node)
{
	struct node* current = node;

	while (current && current->left != NULL)
		current = current->left;

	return current;
}

struct node* deleteNode(struct node* Node, int data)
{
	if (Node == NULL)
		return Node;

	if (data < Node->data)
		Node->left = deleteNode(Node->left, data);

	else if (data > Node->data)
		Node->right = deleteNode(Node->right, data);

	else {
		if (Node->left == NULL) {
			struct node* temp = Node->right;
			free(Node);
			return temp;
		}
		else if (Node->right == NULL) {
			struct node* temp = Node->left;
			free(Node);
			return temp;
		}

		struct node* temp = minValueNode(Node->right);

		Node->data = temp->data;

		Node->right = deleteNode(Node->right, temp->data);
	}
	return Node;
}

int main()
{
    int choice;
    int n;
    int data;
    int i;
    struct node *root= NULL;
printf("\n--------Program on tree node deletion--------");
    printf("\nHow many tree nodes do you want: ");
    scanf("%d",&n);
    i=0;
    while(i<n)
    {
        printf("\nEnter data: ");
        scanf("%d",&data);
        root=insert(root,data);
        i++;
    }
    printf("\n--------Before Deleting--------\nPreorder: ");
    preorder(root);
    printf("\nInorder: ");
    inorder(root);
    printf("\nPostorder: ");
    postorder(root);
    while(choice!=4)
    {
    printf("\n1.Delete Leaf Node\n2.Delete a node having one child\n3.Delete node having two children\n4.Quit\nEnter choice: ");
    scanf("%d",&choice);
    switch(choice)
    {
    case 1:
        printf("\nWhich leaf node do you want to delete ?: ");
        scanf("%d",&data);
        deleteNode(root,data);
        break;
    case 2:printf("\nWhich node having a single child do you want to delete ?: ");
        scanf("%d",&data);
        deleteNode(root,data);
        break;
    case 3:printf("\nWhich node having two children do you want to delete ?: ");
    scanf("%d",&data);
        deleteNode(root,data);
        break;
    case 4: exit(0);
        break;
    }
    printf("\n--------After Deleting--------\nPreorder: ");
    preorder(root);
    printf("\nInorder: ");
    inorder(root);
    printf("\nPostorder: ");
    postorder(root);
    }
    return 0;
}
