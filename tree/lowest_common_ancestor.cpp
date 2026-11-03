
class TreeNode
{
public: 
    int data;
    TreeNode *left, *right;

    TreeNode(int data) : data(data), left(nullptr), right(nullptr) {};
};

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == nullptr)
    {
        return root;
    }

    // checking if we reached p or q
    if (root == p || root == q)
    {
        return root;
    }

    TreeNode *left = lowestCommonAncestor(root->left, p, q);
    TreeNode *right = lowestCommonAncestor(root->right, p, q);

    // if left is null return right
    if (left == nullptr)
        return right;
    else if (right == nullptr)
        return left;
    else
    {
        // if both of them are not null we found our result
        return root;
    }
}
