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

int same_tree(Node *t1, Node *t2)
{

    if (t1 == null || t2 == null)
        return t1 == t2;

    return t1->data == t2->data && same_tree(t1->left, t2->left) && same_tree(t1->right, t2->right);
}

int main()
{
    Node *root = null;

    root = insert(root, 4);
    root = insert(root, 2);
    root = insert(root, 6);
    root = insert(root, 1);
    root = insert(root, 3);
    root = insert(root, 5);
    root = insert(root, 7);

    Node *root2 = null;

    root2 = insert(root2, 4);
    root2 = insert(root2, 2);
    root2 = insert(root2, 6);
    root2 = insert(root2, 1);
    root2 = insert(root2, 3);
    root2 = insert(root2, 5);
    root2 = insert(root2, 7);

    printf("SAME TREE: %d", same_tree(root, root2));

    return 0;
}