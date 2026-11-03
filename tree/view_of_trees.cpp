#include<iostream>
#include <map>
#include <queue>
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



vector<int> top_view(Node *root)
{   

    if(root == null)
    {
        return {};
    }

    map<int, int> mp;
    queue<pair<int ,Node*>> q;

    q.push({0, root});
    while (!q.empty())
    {
        Node *node = q.front().second;
        int ver = q.front().first;
        q.pop();

        if(mp.find(ver) == mp.end())
        {
            mp[ver] = node->data;
        }

        if(node->left)
        {
            q.push({ver - 1, node->left});
        }
        if(node->right)
        {
            q.push({ver + 1, node->right});
        }
    }

    vector<int> res;

    for(auto i : mp)
    {
        res.push_back(i.second);
    }

    return res;
}


vector<int> bottom_view(Node *root)
{   

    if(root == null)
    {
        return {};
    }

    map<int, int> mp;
    queue<pair<int ,Node*>> q;

    q.push({0, root});
    while (!q.empty())
    {
        Node *node = q.front().second;
        int ver = q.front().first;
        q.pop();

    
        mp[ver] = node->data;
        

        if(node->left)
        {
            q.push({ver - 1, node->left});
        }
        if(node->right)
        {
            q.push({ver + 1, node->right});
        }
    }

    vector<int> res;

    for(auto i : mp)
    {
        res.push_back(i.second);
    }

    return res;
}

vector<int> right_view(Node *root)
{
    vector<int>res;

    queue<Node*> q;

    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        Node *last;

        for(int i = 0; i < size; i++)
        {
            last = q.front();
            q.pop();

            if(last->left)
            {
                q.push(last->left);
            }

            if(last->right)
            {
                q.push(last->right);
            }
        }

        res.push_back(last->data);

    }

    return res;
    
}


vector<int> left_view(Node *root)
{
    vector<int>res;

    queue<Node*> q;

    q.push(root);

    while (!q.empty())
    {
        int size = q.size();
        Node *first = null;

        for(int i = 0; i < size; i++)
        {
            first = q.front();
            q.pop();

            
            if(i == 0)
                res.push_back(first->data);


            if(first->left)
            {
                q.push(first->left);
            }

            if(first->right)
            {
                q.push(first->right);
            }
        }


    }

    return res;
    
}

void right_view2(Node *root, int level, vector<int> &res)
{
    if(root == null) return;

    if(level == res.size())
        res.push_back(root->data);

    right_view2(root->right, level + 1, res);
    right_view2(root->left, level + 1, res);
}

void left_view2(Node *root, int level, vector<int> &res)
{
    if(root == null) return;

    if(level == res.size())
        res.push_back(root->data);

    left_view2(root->left, level + 1, res);
    left_view2(root->right, level + 1, res);
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



    vector<int> top = top_view(root);
    vector<int> bottom = bottom_view(root);
    vector<int> right = right_view(root);
    vector<int> left = left_view(root);


    cout << "TOP VIEW:\n";
    for(int i : top)
    {
        cout << i << ' ';
    }

    cout << '\n';


    cout << "BOTTOM VIEW:\n";
    for(int i : bottom)
    {
        cout << i << ' ';
    }

    cout << '\n';


    cout << "RIGHT VIEW:\n";
    for(int i : right)
    {
        cout << i << ' ';
    }

    cout << '\n';

    vector<int> right2;
    right_view2(root, 0, right2);
    cout << "RIGHT VIEW RECURSIVE:\n";
    for(int i : right2)
    {
        cout << i << ' ';
    }

    cout << '\n';


    cout << "LEFT VIEW:\n";
    for(int i : left)
    {
        cout << i << ' ';
    }

    cout << '\n';

    vector<int> left2;
    left_view2(root, 0, left2);
    cout << "LEFT VIEW RECURSIVE:\n";
    for(int i : left2)
    {
        cout << i << ' ';
    }

    cout << '\n';


    return 0;
}
