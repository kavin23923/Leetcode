/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  bool isBalanced(TreeNode* root) {
    bool flag = true;
    deep(root, &flag);
    return flag;
  }
  
  int deep(TreeNode* root, bool *flag) {
    if (!root) {
      return 0;
    }
    int l = deep(root->left, flag);
    int r = deep(root->right, flag);
    if (abs(l - r) > 1) {
      *flag = false;
    } 
    return max(l, r) + 1;
  }
};
