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
  bool isCousins(TreeNode* root, int x, int y) {
    int count = 0;
    queue<TreeNode*> level;
    
    if (!root || root->val == x || root->val == y) return false;
    level.push(root);
    while (level.size() > 0 && count == 0) {
      int round = level.size();
      for (int i = 0; i < round; i++) {
        int flag = 0;
        TreeNode* now = level.front();
        level.pop();
        if (now->left) {
          if (now->left->val == x || now->left->val == y) {
            flag++;
            count++;
          }
          level.push(now->left);
        }
        if (now->right) {
          if (now->right->val == x || now->right->val == y) {
            flag++;
            count++;
          }
          level.push(now->right);
        }
        if (flag == 2) return false;
      }
    }

    return count == 2;
  }
};
