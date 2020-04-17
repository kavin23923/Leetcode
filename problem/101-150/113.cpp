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
  vector<vector<int>> pathSum(TreeNode* root, int sum) {
    vector<vector<int>> res;
    vector<int> tmp;
    traverse(root, sum, res, tmp);
    return res;
  }
  
  void traverse(TreeNode* root, int sum, vector<vector<int>> &res, vector<int> &tmp) {
    if (!root) return;
    tmp.push_back(root->val);
    if (!root->left && !root->right && sum == root->val) {
      res.push_back(tmp);
    } else {
      traverse(root->left, sum - root->val, res, tmp);
      traverse(root->right, sum - root->val, res, tmp);
    }
    tmp.pop_back();
  }
};
