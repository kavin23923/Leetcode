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
  int findTilt(TreeNode* root) {
    int res = 0;
    sum(root, &res);
    return res;
  }
  
  int sum(TreeNode* root, int* res) {
    if (!root) return 0;
    int lsum = sum(root->left, res);
    int rsum = sum(root->right, res);
    *res += abs(lsum - rsum);
    return lsum + rsum + root->val;
  }
};
