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
  int widthOfBinaryTree(TreeNode* root) {
    if (!root) return 0;
    unsigned int res = 0;
    unsigned int right;
    unsigned int left;
    int i;
    int size;
    TreeNode *tmp;
    queue<pair<TreeNode*, unsigned int>> node;
    node.push(make_pair(root, 0));
    
    while (!node.empty()) {
      size = node.size();
      left = node.front().second;
      for (i = 0; i < size; i++) {
        right = node.front().second;
        tmp = node.front().first;
        node.pop();
        if (tmp->left) {
          node.push(make_pair(tmp->left, right * 2 + 1));
        }
        if (tmp->right) {
          node.push(make_pair(tmp->right, right * 2 + 2));
        }
      }
      res = max(right - left + 1, res);
    }
    return (int)res;
  }
};
