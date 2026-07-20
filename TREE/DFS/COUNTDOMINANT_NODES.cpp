 #include<iostream>
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
    int count=0;
    int solve(TreeNode* root) {
        if(root==NULL) return 0;
        int left=solve(root->left);
        int right=solve(root->right);
        int maxi=root->val;
        if(left>maxi) maxi=left;
        if(right>maxi) maxi=right;
        if(maxi==root->val) count++;
        return maxi;
    }
    int countDominantNodes(TreeNode* root) {
         solve(root);
         return count;
    }
};