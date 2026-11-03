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

int isLeaf(Node *n)
{
    return n->right == null && n->left == null;
}

void addLeft(Node *root, int res[], int *idx)
{
    if(root == null || isLeaf(root)) return;

    res[(*idx)++] = root->data;

    if(root->left)
        addLeft(root->left, res, idx);
    else if(root->right)
        addLeft(root->right, res, idx);
}


void addLeaves(Node *root, int res[], int *idx)
{
    if(root == null) return;

    if(isLeaf(root))
    {
        res[(*idx)++] = root->data;
        return;

    }

  
    addLeaves(root->left, res, idx);  
    addLeaves(root->right, res, idx);
}


void addRight(Node *root, int res[], int *idx)
{
    if(root == null || isLeaf(root)) return;

    if(root->right)
        addRight(root->right, res, idx);
    else if(root->left)
        addRight(root->left, res, idx);

    res[(*idx)++] = root->data;


}

void boundary_traversal(Node *root)
{

    int res[100] = {0};
    int idx = 0;

    if (!root)
        return;


    if (!isLeaf(root))
        res[idx++] = root->data;

    addLeft(root->left, res, &idx);
    addLeaves(root, res, &idx);
    addRight(root->right, res, &idx);

    for(int i = 0; i < idx; i++)
    {
        printf("%d ", res[i]);
    }

    printf("\n");
 
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

    boundary_traversal(root);
    

    return 0;
}