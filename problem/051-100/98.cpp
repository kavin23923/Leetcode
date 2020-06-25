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
  bool isValidBST(TreeNode* root) {
    int maxv = INT_MIN, minv = INT_MAX;
    return isValid(root, &maxv, &minv);         
  }
  
  bool isValid(TreeNode* root, int *maxv, int *minv) {
    if (!root) {
      return true;
    }
    int l_max = INT_MIN, l_min = INT_MAX, r_max = INT_MIN, r_min = INT_MAX;
    if (root->left) {
      bool l = isValid(root->left, &l_max, &l_min);
      if (!l || l_max >= root->val) return false;
    }
    if (root->right) {
      bool r = isValid(root->right, &r_max, &r_min);
      if (!r || r_min <= root->val) return false;
    }
    *maxv = max(root->val, r_max);
    *minv = min(root->val, l_min);
    return true;
  }
};
