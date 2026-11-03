#include<iostream>
using namespace std;

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
    Node *newNode = (Node*)malloc(sizeof(Node));
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




int symmetricHelp(Node *left, Node *right)
{
    if(left == null || right == null)
        return left == right;

    return left->data == right->data && symmetricHelp(left->right, right->left) && symmetricHelp(left->left, right->right);

}

int isSymmetric(Node *root)
{
    return root == null || symmetricHelp(root->left, root->right);
}


int main(){
    
    Node *root = NULL;


    root = insert(root, 4);
    root = insert(root, 2);
    root = insert(root, 6);
    root = insert(root, 1);
    root = insert(root, 3);
    root = insert(root, 5);
    root = insert(root, 7);



    cout << isSymmetric(root);




    return 0;
}