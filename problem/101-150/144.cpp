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
  vector<int> preorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> node;
    TreeNode *tmp;
    
    if (root) {
      node.push(root);
    }    
    while (!node.empty()) {
      tmp = node.top();
      node.pop();
      res.push_back(tmp->val);
      if (tmp->right) node.push(tmp->right);
      if (tmp->left) node.push(tmp->left);
    }
    return res;
  }
};
