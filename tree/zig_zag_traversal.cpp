#include <stdio.h>
#include <stdlib.h>
#include <queue>
#include <iostream>
#include <vector>
using namespace std;



#define null NULL

typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node, TreeNode;

Node *getNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
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



void newLine()
{
    printf("\n");
}

void print(char *str)
{
    printf("%s\n", str);
}


vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if(root == nullptr) return res;
        queue<TreeNode*> q;
        q.push(root);
        
        bool flag = true;

        while(!q.empty())
        {
            int size = q.size();
            vector<int> a(size);
            int idx = (flag?0:size-1);

            for(int i = 0; i < size; i ++)
            {
                TreeNode *f = q.front();
                q.pop();

                if(flag)
                    a[idx++] = f->data;
                                           
                else
                    a[idx--] = f->data;


                if(f->left)
                    q.push(f->left);
                if(f->right)
                    q.push(f->right);
            }

            if(size != 0)  
                res.push_back(a);

            flag = !flag;
          
        }
        return res;  
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


    vector<vector<int>> res = zigzagLevelOrder(root);

    for(auto a : res)
    {
        for(auto b : a)
        {
            cout << b << ' ';
        }
        cout << '\n';
    }
   

    return 0;
}
