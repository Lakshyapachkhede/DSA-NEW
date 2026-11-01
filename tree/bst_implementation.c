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

Node *delete(Node *root, int data)
{
    if (root == null)
        return null;

    if (data < root->data)
    {
        root->left = delete(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = delete(root->right, data);
    }
    else
    {
        if (root->left == null)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == null)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        else
        {
            Node *inOrderSuccessor = findMin(root->right);
            root->data = inOrderSuccessor->data;
            root->right = delete(root->right, inOrderSuccessor->data);
        }
    }
    return root;
    
}

void preorder(Node *root)
{
    if (root == null)
        return;

    printf(" %d", root->data);
    preorder(root->left);
    preorder(root->right);
}

void postorder(Node *root)
{
    if (root == null)
        return;

    postorder(root->left);
    postorder(root->right);
    printf(" %d", root->data);
}

void inorder(Node *root)
{
    if (root == null)
        return;

    inorder(root->left);
    printf(" %d", root->data);
    inorder(root->right);
}

void levelOrder(Node *root)
{

    printf("Level Order Traversal:\n");

    if (root == NULL)
    {
        printf("\n");
        return;
    }

    Node *queue[100];
    int front = 0, rear = 0;

    queue[rear++] = root;
    

    while (front < rear)
    {
        Node *ptr = queue[front++];
        printf("%d ", ptr->data);
        if(ptr->left)
            queue[rear++] = ptr->left;
        if(ptr->right)
            queue[rear++] = ptr->right;
    }

    printf("\n");
    
}

void newLine()
{
    printf("\n");
}

void print(char *str)
{
    printf("%s\n", str);
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

    root = delete(root, 10);

    print("Preorder Traversal:");
    preorder(root);
    newLine();

    print("Inorder Traversal:");
    inorder(root);
    newLine();

    print("Postorder Traversal:");
    postorder(root);
    newLine();

    levelOrder(root);


    return 0;
}
