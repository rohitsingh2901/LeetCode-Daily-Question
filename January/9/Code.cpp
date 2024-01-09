
#include<bits/stdc++.h>
using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };

class Solution {
public:
    // Helper method to perform depth-first search and gather leaf node values
    void dfs(TreeNode* root, vector<int>& arr){
        if (root == NULL) return;
        if (!root->left && !root->right) 
            arr.push_back(root->val);  // Add leaf node value to the array
        dfs(root->left, arr);  // Recursively traverse left subtree
        dfs(root->right, arr);  // Recursively traverse right subtree
    }

    // Main function to check if two trees are leaf-similar
    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        vector<int> arr1, arr2;
        dfs(root1, arr1);  // Get leaf node values for tree 1
        dfs(root2, arr2);  // Get leaf node values for tree 2
        return arr1 == arr2;  // Compare leaf node value arrays for equality
    }
};
