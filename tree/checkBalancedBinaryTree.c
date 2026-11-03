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

int check1(Node *root)
{
    if (root == null) return 1;

    int lh = height(root->left);
    int rh = height(root->right);

    if(abs(rh - lh) > 1) return 0;

    int left = check1(root->left);
    int right = check1(root->right);

    if(!left || !right) return 0;

    return 1;

}

int check(Node *root)
{
    if (root == null)
        return 0;

        
    int lh = height(root->left);
    int rh = height(root->right);

    if(lh == -1 || rh == -1 || abs(lh - rh) > 1) return -1;


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



    printf("IS BALANCED BST %d", check(root) > -1 ? 1 : 0);

    return 0;
}
