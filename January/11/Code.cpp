
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
    // Function to calculate the maximum difference between ancestor nodes
    int maxAncestorDiff(TreeNode* root, int maxValue = -1e9, int minValue = 1e9) {
        // Base case: If the current node is nullptr (empty subtree), return the difference
        if (root == nullptr) return (maxValue - minValue);
        
        // Update maxValue and minValue based on the current node's value
        maxValue = max(maxValue, root->val);
        minValue = min(minValue, root->val);
        
        // Recursively calculate the maximum difference for the left and right subtrees
        int leftDiff = maxAncestorDiff(root->left, maxValue, minValue);
        int rightDiff = maxAncestorDiff(root->right, maxValue, minValue);
        
        // Return the maximum difference among left subtree, right subtree, and current subtree
        return max(leftDiff, rightDiff);
    }
};
