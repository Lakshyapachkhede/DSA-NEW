#include <stdio.h>
#include <stdlib.h>

#define null NULL

typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;

Node *getNode(int data)
{
    Node *newNode = malloc(sizeof(Node));
    if (newNode == null)
        return null;

    newNode->data = data;
    newNode->left = null;
    newNode->right = null;

    return newNode;
}

Node *insert(Node *root, int data)
{
    if (root == null)
        return getNode(data);

    if (data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);

    return root;
}



int max(int a, int b)
{
    return a > b ? a : b;
}


int diameter(Node *root, int *d)
{
    if (root == null)
        return 0;

        
    int lh = diameter(root->left, d);
    int rh = diameter(root->right, d);

    *d  = max(lh + rh, *d);


    return 1 + max(lh, rh);
}
int main()
{

    Node *root = NULL;


    root = insert(root, 4);
    root = insert(root, 2);
    root = insert(root, 6);
    root = insert(root, 1);
    root = insert(root, 3);
    root = insert(root, 5);
    root = insert(root, 7);

    int d = -1;
    diameter(root, &d);
    printf("DIAMETER OF BST %d", d);

    return 0;
}
