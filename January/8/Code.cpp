#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    void inorder(TreeNode *root, int low, int high, int &s)
    {
        if (root == NULL)
        {
            return;
        }
        inorder(root->left, low, high, s);
        if (root->val >= low && root->val <= high)
        {
            s += root->val;
        }
        inorder(root->right, low, high, s);
    }

    int rangeSumBST(TreeNode *root, int low, int high)
    {
        int s = 0;
        inorder(root, low, high, s);
        return s;
    }
};