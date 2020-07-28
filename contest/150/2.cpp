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
  int maxLevelSum(TreeNode* root) {
    int sum = INT_MIN, res, l = 1;
    queue<TreeNode*> level;
    TreeNode *tmp;
    
    level.push(root);
    while (!level.empty()) {
      int size = level.size();
      int now = 0;
      for (int i = 0; i < size; i++) {
        tmp = level.front();
        level.pop();
        now += tmp->val;
        if (tmp->left) level.push(tmp->left);
        if (tmp->right) level.push(tmp->right);
      }
      if (now > sum) {
        sum = now;
        res = l;
      }
      l++;
    }
    return res;
  }
};
