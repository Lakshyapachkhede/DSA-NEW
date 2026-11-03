#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <iostream>
#include <map>
#include <set>

using namespace std;

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

vector<vector<int>> verticalTraversal(Node *root)
{
    if (root == NULL)
        return {};

    map<int, map<int, multiset<int>>> mp;
    queue<tuple<Node*, int, int>> queue;
    queue.push({root, 0, 0});

   
    while (!queue.empty())
    {
   
        auto front = queue.front();
        queue.pop();

        Node *node = get<0>(front);
        int row = get<1>(front);
        int col = get<2>(front);

        mp[col][row].insert(node->data);

        if(node->left)
        {          
            queue.push({node->left,row+1, col - 1});
        }

        if(node->right)
        {
            queue.push({node->right, row+1, col + 1});
        }

        
    }

    vector<vector<int>> res;

    for (auto column : mp)
    {
        vector<int> temp;

        for (auto level : column.second)
        {
            for (int value : level.second)
            {
                temp.push_back(value);
            }
        }

        res.push_back(temp);
    }


    return res;
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

    vector<vector<int>> res = verticalTraversal(root);

    for(auto level : res)
    {
        for(int n : level)
        {
            cout << n << ' ';
        }
        cout << '\n';
    }

    return 0;
}