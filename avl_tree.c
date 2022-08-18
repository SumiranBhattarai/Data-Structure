/*
step1: start;
step2: create function for newnode
step3: create a struct Node with data member key,height and self referential struct pointer left and right
step4: create function height which takes in a node and return its height
step5: create function max which returns the maximum height of the subtree
step6: create function balanceFactor which returns the height of right subtree - left subtree
step7: create function insertNode
            insert data and node in a bst fashion
            increment the root height at each insertion
            calculate balance factor as well
            if balance > 1 & data < node-left-data
                rightRotate

            if balance < -1 &&key > node-right-key
                leftRotate

            if balance > 1 & key > node-left-key
                leftrotate left node
                then rightRotate

            if balance < -1 & key < node-right-key
                rightrotate right node
                then leftrotate

step8: create function for preorder,inorder and postorder node traversal
step9: create a tree and balance the tree during creation
step10: print preorder, inorder and postorder traversal for the tree
*/


#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int key;
    struct Node *left;
    struct Node *right;
    int height;
};

int height(struct Node *N)
{	 	  	   	   	  		  	 	
    if (N == NULL)
        return 0;
    return N->height;
}

int max(int a, int b)
{
    return (a > b) ? a : b;
}

struct Node *newNode(int key)
{
    struct Node *node = (struct Node *)
                        malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    return (node);
}

// Right rotate
struct Node *rightRotate(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;

    return x;
}

// Left rotate
struct Node *leftRotate(struct Node *x)
{	 	  	   	   	  		  	 	
    struct Node *y = x->right;
    struct Node *T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;

    return y;
}

int getBalance(struct Node *N)
{
    if (N == NULL)
        return 0;
    return height(N->left) - height(N->right);
}

struct Node *insertNode(struct Node *node, int key)
{
    if (node == NULL)
        return (newNode(key));

    if (key < node->key)
        node->left = insertNode(node->left, key);
    else if (key > node->key)
        node->right = insertNode(node->right, key);
    else
        return node;

    node->height = 1 + max(height(node->left),
                           height(node->right));

    int balance = getBalance(node);
    if (balance > 1 && key < node->left->key)
        return rightRotate(node);

    if (balance < -1 && key > node->right->key)
        return leftRotate(node);

    if (balance > 1 && key > node->left->key)
    {	 	  	   	   	  		  	 	
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    if (balance < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}
void printPreOrder(struct Node *root)
{
    if (root != NULL)
    {
        printf("%d ", root->key);
        printPreOrder(root->left);
        printPreOrder(root->right);
    }
}


void printInOrder(struct Node *root)
{
    if (root != NULL)
    {
        printPreOrder(root->left);
        printf("%d ", root->key);
        printPreOrder(root->right);
    }
}

void printPostOrder(struct Node *root)
{
    if (root != NULL)
    {	 	  	   	   	  		  	 	
        printPreOrder(root->left);
        printPreOrder(root->right);
        printf("%d ", root->key);
    }
}
int main()
{
    struct Node *root = NULL;

    root = insertNode(root, 10);
    root = insertNode(root, 15);
    root = insertNode(root, 25);
    root = insertNode(root, 30);
    root = insertNode(root, 35);
    root = insertNode(root, 20);

    printf("\nBefore balancing: ");
    printf("\nPreorder Traversal:  10 15 25 20 30 35");
    printf("\nInorder Traversal:   10 15 20 25 30 35");
    printf("\nPostorder Traversal: 20 35 30 25 15 10");

    printf("\n\nAfter balancing: ");
    printf("\nPreorder Traversal:  ");
    printPreOrder(root);

    printf("\nInorder Traversal:   ");
    printInOrder(root);

    printf("\nPostorder Traversal: ");
    printPostOrder(root);

    return 0;
}
	 	  	   	   	  		  	 	
