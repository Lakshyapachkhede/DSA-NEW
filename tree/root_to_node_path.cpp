#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node(int data) : data(data), left(nullptr), right(nullptr) {};



};


Node* insert(Node *root, int data)
{
    if(root == nullptr) return new Node(data);

    if(data < root->data)
        root->left = insert(root->left, data);
    else
        root->right = insert(root->right, data);
    
    return root;        
}

void inorder(Node *root)
{
    if(root == nullptr) return;

    inorder(root->left);
    cout << root->data << ' ';
    inorder(root->right);

}

bool root_to_node_path(Node *root, int x, vector<int> &res)
{
    if(root == nullptr) return false;

    res.push_back(root->data);
    
    if(root->data == x)
        return true;

    if(root_to_node_path(root->left, x, res) || root_to_node_path(root->right, x, res))
        return true;
    
    res.pop_back();

    return false;
}

bool isLeaf(Node *node)
{
    return node->right == nullptr && node->left == nullptr;
}

void root_to_leaves(Node *root, vector<int> &path, vector<vector<int>> &paths)
{
    if(root == nullptr) return;

    path.push_back(root->data);

    if(isLeaf(root))
    {
        paths.push_back(path);      
    }
    else
    {
        root_to_leaves(root->left, path, paths);
        root_to_leaves(root->right, path, paths);
    }
         
    path.pop_back();
}


void root_to_leaves_leetcode(Node *root, string &path, vector<string> &paths)
{
    if(root == nullptr) return;

    string temp = path;

    if(path.size() == 0)
    {
        path = to_string(root->data);
    }
    else
    {
        path += "->";
        path += to_string(root->data);
    }

    if(root->left == nullptr && root->right == nullptr)
    {
        paths.push_back(path);
    }
    else{
        root_to_leaves_leetcode(root->left, path, paths);
        root_to_leaves_leetcode(root->right, path, paths);
    }
    path = temp;
}



int main()
{
    Node *root = nullptr;
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 60);
    root = insert(root, 30);
    root = insert(root, 5);
    root = insert(root, 2);
    root = insert(root, 8);


    inorder(root);

    cout << '\n';

    vector<int> res;

    root_to_node_path(root, 30, res);

    for(auto i : res)
        cout << i << ' ';

    cout << "\n";

    res.clear();
    vector<vector<int>> res2;
    root_to_leaves(root, res, res2);

    for(auto i : res2)
    {
        for(int j = 0; j < i.size(); j++)
        {
            cout << i[j];
            if(j != i.size() - 1)
                cout << "->";
        }
        cout << "\n";
    }

    cout << "LEETCODE 257\n";

    string path;
    vector<string> paths;
    root_to_leaves_leetcode(root, path, paths);



    for(auto path : paths)
    {
        cout << path << '\n';
    }


    return 0;
}