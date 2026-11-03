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

Node *findMin(Node *root)
{
    while (root->left != null)
    {
        root = root->left;
    }

    return root;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int height(Node *root)
{
    if (root == null)
        return 0;
    return 1 + max(height(root->left), height(root->right));
}

int main()
{

    Node *root = NULL;
    root = insert(root, 10);
    root = insert(root, 12);
    root = insert(root, 6);
    root = insert(root, 7);
    root = insert(root, 5);
    root = insert(root, 16);
    root = insert(root, 15);

    printf("HEIGHT OF BST %d", height(root));

    return 0;
}
