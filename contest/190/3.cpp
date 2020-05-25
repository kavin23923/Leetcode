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
  int pseudoPalindromicPaths (TreeNode* root) {
    vector<int> count(10);
    int res = 0;
    traverse(root, count, &res);
    return res;
  }
  
  void traverse(TreeNode* root, vector<int> &count, int *res) {
    count[root->val]++;
    if (!root->left && !root->right) {
      if (judge(count)) {
        *res += 1;
      }
      count[root->val]--;
      return;
    }
    
    if (root->left) {
      traverse(root->left, count, res);
    }
    if (root->right) {
      traverse(root->right, count, res);
    }
    count[root->val]--;
  }
  
  bool judge(vector<int> &count) {
    int odd = 0;
    for (int i = 1; i <= 9; i++) {
      if (count[i] & 1) {
        odd++;
      }
    }
    return odd <= 1;
  }
};
