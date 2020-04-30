/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  int maxPathSum(TreeNode* root) {
    int res = INT_MIN;
    sum(root, &res);
    return res;
  }
  
  int sum(TreeNode* root, int *res) {
    if (!root) {
      return 0;
    }
    int l = max(sum(root->left, res), 0);
    int r = max(sum(root->right, res), 0);
    *res = max(*res, root->val + l + r);
    return max(l, r) + root->val;
  }
};
/**
 * For the recursion part, if we use max(return value, 0), the logic for value updating can be much simpler,
 * as the negative value can be handled properly
 */
