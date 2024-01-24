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
    int digits[10];
    int count=0;
    bool isPalindrome(){
        int odd=0;
        for(int i=1;i<=9;i++){
            if(digits[i]%2!=0){
                odd++;
            }
        }
        if(odd>1){
            return 0;
        }
        return 1;
    }

    void dfs(TreeNode* root){
        if(root==nullptr){
            return;
        }
        digits[root->val]++;
        if(root->left==nullptr && root->right==nullptr){
            if(isPalindrome()){
                count++;
            }
        }
        else{
            dfs(root->left);
            dfs(root->right);
        }
        digits[root->val]--;
    }

    int pseudoPalindromicPaths (TreeNode* root) {
        dfs(root);
        return count;
    }
};