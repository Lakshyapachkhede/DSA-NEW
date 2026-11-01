#include <iostream>
#include <vector>
#include <stack>
using namespace std;


#define null NULL

typedef struct Node
{
    int data;
    struct Node *left, *right;
} Node;

Node *getNode(int data)
{
    Node *newNode = new Node;
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

void allTraversals(Node *root)
{
    if(root == null) return;

    stack<pair<Node*, int>> s;

    s.push({root, 1});

    vector<int> pre;
    vector<int> post;
    vector<int> in;

    while (!s.empty())
    {
        pair p = s.top();

        if(p.second == 1)
        {
            pre.push_back(p.first->data);
            s.top().second++;
            if(p.first->left)
                s.push({p.first->left, 1});
        }
        else if(p.second == 2)
        {
            in.push_back(p.first->data);
            s.top().second++;
            if(p.first->right)
                s.push({p.first->right, 1});
        }
        else if(p.second == 3)
        {
            post.push_back(p.first->data);
            s.pop();
        }

    }
    
    cout << "PREORDER:  ";
    for(int val : pre) cout << val << " ";
    cout << "\nINORDER:   ";
    for(int val : in) cout << val << " ";
    cout << "\nPOSTORDER: ";
    for(int val : post) cout << val << " ";
    cout << endl;

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
    allTraversals(root);
    
    return 0;
}