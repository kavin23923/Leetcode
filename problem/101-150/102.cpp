/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * x
 */
class Solution {
public:
  vector<vector<int>> levelOrder(TreeNode* root) {
    vector<vector<int>> res;
    queue<TreeNode*> level;
    TreeNode* front;
    int size;
    
    if (!root) return res;
    
    level.push(root);
    while (!level.empty()) {
      size = level.size();
      vector<int> tmp;
      for (int i = 0; i < size; i++) {
        front = level.front();
        level.pop();
        tmp.push_back(front->val);
        if (front->left) {
          level.push(front->left);
        }
        if (front->right) {
          level.push(front->right);
        }
      }
      res.push_back(tmp);
    }
    
    return res;
  }
};
