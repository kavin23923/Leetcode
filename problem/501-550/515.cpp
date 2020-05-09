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
  vector<int> largestValues(TreeNode* root) {
    vector<int> res;
    queue<TreeNode*> node;
    TreeNode* tmp;
    int size, large;
    
    if (root) node.push(root);
    while (node.size() > 0) {
      size = node.size();
      large = INT_MIN;
      for (int i = 0; i < size; i++) {
        tmp = node.front();
        node.pop();
        large = max(large, tmp->val);
        if (tmp->left) node.push(tmp->left);
        if (tmp->right) node.push(tmp->right);
      }
      res.push_back(large);
    }
    return res;
  }
};
