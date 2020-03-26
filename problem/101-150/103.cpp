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
  vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> res;
    stack<TreeNode*> target;

    if (!root) return res;
    target.push(root);

    while (!target.empty()) {
      stack<TreeNode*> next;
      vector<int> level;
      TreeNode* tmp;
      int round = res.size() % 2;
      while (!target.empty()) {
        tmp = target.top();
        target.pop();
        level.push_back(tmp->val);
        if (round == 0) {
          if (tmp->left) next.push(tmp->left);
          if (tmp->right) next.push(tmp->right);
        } else {
          if (tmp->right) next.push(tmp->right);
          if (tmp->left) next.push(tmp->left);
        }
      }
      res.push_back(level);
      target = next;
    }
    return res;
  }
};
