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
//   vector<int> postorderTraversal(TreeNode* root) {
//     vector<int> res;      
//     postorder(root, res);
//     return res;
//   }
  
//   void postorder(TreeNode *root, vector<int> &res) {
//     if (!root) return;
//     postorder(root->left, res);
//     postorder(root->right, res);
//     res.push_back(root->val);
//   }
  vector<int> postorderTraversal(TreeNode* root) {
    vector<int> res;
    stack<TreeNode*> node;
    TreeNode *tmp;
    if (!root) return res;
    
    node.push(root);
    while(!node.empty()) {
      tmp = node.top();
      node.pop();
      res.push_back(tmp->val);
      if (tmp->left) node.push(tmp->left);
      if (tmp->right) node.push(tmp->right);
    }
    
    reverse(res.begin(), res.end());
    return res;
  }
};
