
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

    // Function to create a mapping of nodes and their parent nodes
    void f(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& mp) {
        if (root == NULL) return;

        if (root->left) mp[root->left] = root;
        if (root->right) mp[root->right] = root;

        f(root->left, mp);
        f(root->right, mp);
    }

    // Function to find the node with the given value 'st'
    TreeNode* findnode(int st, TreeNode* root) {
        if (root == NULL) return NULL;

        if (root->val == st) return root;

        TreeNode* fn = findnode(st, root->left);
        if (!fn) fn = findnode(st, root->right);
        return fn;
    }

    int amountOfTime(TreeNode* root, int start) {
        // Finding the node with the given 'start' value
        TreeNode* src = findnode(start, root);

        // Mapping nodes to their parent nodes
        unordered_map<TreeNode*, TreeNode*> mp;
        f(root, mp);

        // Initializing a queue for BFS traversal
        queue<TreeNode*> q;
        q.push(src);

        // Visited map to track infected nodes
        unordered_map<TreeNode*, bool> vis;
        vis[src] = true;
        int c = 0; // Counter for time taken

        // BFS traversal to infect nodes
        while (!q.empty()) {
            int len = q.size();
            while (len--) {
                TreeNode* node = q.front();
                q.pop();
                vis[node] = true;

                // Enqueue adjacent nodes if uninfected and mark as visited
                if (node->left && !vis[node->left]) {
                    q.push(node->left);
                    vis[node->left] = true;
                }
                if (node->right && !vis[node->right]) {
                    q.push(node->right);
                    vis[node->right] = true;
                }
                // Enqueue parent node if uninfected and mark as visited
                if (mp[node] && !vis[mp[node]]) {
                    q.push(mp[node]);
                    vis[mp[node]] = true;
                }
            }
            c++; // Increment time counter for each level of infection
        }
        return c - 1; // Subtract 1 as the initial infected node is already counted at time 0
    }
};
