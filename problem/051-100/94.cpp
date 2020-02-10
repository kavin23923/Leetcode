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
  vector<int> inorderTraversal(TreeNode* root) {
    stack<TreeNode*> node;
    vector<int> res;
    
    while (root) {
      node.push(root);
      root = root->left;
    }
    
    while (!node.empty()) {
      TreeNode* tmp = node.top();
      res.push_back(tmp->val);
      node.pop();
      tmp = tmp->right;
      while (tmp) {
        node.push(tmp);
        tmp = tmp->left;
      }
    }
    return res;
  }
};
