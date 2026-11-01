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




void preorder(Node *root)
{
    if(root == null) return;

    Node *stack[10];
    int top = -1;

    stack[++top] = root;

    while(top != -1)
    {
        Node *ptr = stack[top--];

        printf("%d ", ptr->data);


        if(ptr->right)
            stack[++top] = ptr->right;
        if(ptr->left)
            stack[++top] = ptr->left;
    }


}


void inorder(Node *root)
{
    if(root == null) return;

    Node *stack[10];
    int top = -1;
    Node *ptr = root;

    while (ptr != null || top != -1)
    {

        while (ptr != null)
        {
            stack[++top] = ptr;
            ptr = ptr->left;
        }

        ptr = stack[top--];
        printf("%d ", ptr->data);

        ptr = ptr->right;
        
    }
  
}

// 2 stack
void postorder2(Node *root)
{
    if(root == null) return;

    Node *s1[10];
    Node *s2[10];
    int top1 = -1;
    int top2 = -1;
    Node *ptr = root;
    s1[++top1] = ptr;

    while(top1 != -1)
    {
        Node *temp = s1[top1--];
        s2[++top2] = temp;

        if(temp->left)
            s1[++top1] = temp->left;
        if(temp->right)
            s1[++top1] = temp->right;

    }

    while (top2 != -1)
    {
        printf("%d ", s2[top2--]->data);
    }
}



void postorder(Node *root)
{
    if(root == null) return;

    Node *stack[10];
    int top = -1;
    Node *curr = root;


    while(curr != null || top != -1)
    {
        if(curr != null)
        {
            stack[++top] = curr;
            curr = curr->left;
        }
        else
        {
            Node *temp = stack[top]->right;
            if(temp == null)
            {
                temp = stack[top--];
                printf("%d ", temp->data);

                while (top != -1 && temp == stack[top]->right)
                {
                    temp = stack[top--];
                    printf("%d ", temp->data);
                }
            }
            else
            {
                curr = temp;
            }
        }

    }

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


    print("Preorder Traversal:");
    preorder(root);
    newLine();

    print("Inorder Traversal:");
    inorder(root);
    newLine();

    print("Postorder 2 stack Traversal:");
    postorder2(root);
    newLine();

    print("Postorder 1 stack Traversal:");
    postorder(root);
    newLine();

    levelOrder(root);


    return 0;
}
