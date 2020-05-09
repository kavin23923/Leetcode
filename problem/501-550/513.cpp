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
  int findBottomLeftValue(TreeNode* root) {
    int res, size;
    queue<TreeNode*> node;
    TreeNode* tmp;
    
    node.push(root);
    while (!node.empty()) {
      size = node.size();
      res = node.front()->val;
      for (int i = 0; i < size; i++) {
        tmp = node.front();
        node.pop();
        if (tmp->left) node.push(tmp->left);
        if (tmp->right) node.push(tmp->right);
      }
    }
    return res;
  }
};
