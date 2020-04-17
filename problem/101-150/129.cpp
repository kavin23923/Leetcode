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
  int sumNumbers(TreeNode* root) {
    int res = 0;
    traverse(root, 0, &res);
    return res;
  }
  
  void traverse(TreeNode* root, int now, int *res) {
    if (!root) {
      return;
    }
    now = now * 10 + root->val;
    if (!root->left && !root->right) {
      *res += now;
    } else {
      traverse(root->left, now, res);
      traverse(root->right, now, res);
    }
  }
};
