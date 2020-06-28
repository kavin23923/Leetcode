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
  int countNodes(TreeNode* root) {
    int l = left(root);
    int r = right(root);
    return l == r ? (1 << l) - 1 : 1 + countNodes(root->left) + countNodes(root->right); 
  }
  
  int left(TreeNode *root) {
    return root == NULL ? 0 : 1 + left(root->left);
  }
  
  int right(TreeNode *root) {
    return root == NULL ? 0 : 1 + right(root->right);
  }
};
