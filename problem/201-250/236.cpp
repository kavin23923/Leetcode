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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
      if (!root) return NULL;
      TreeNode* l = lowestCommonAncestor(root->left, p, q);
      TreeNode* r = lowestCommonAncestor(root->right, p, q);
      if (l && r) {
        return root;
      } else if ((l || r) && (root->val == p->val || root->val == q->val)) {
        return root;
      } else if (root->val == p->val || root->val == q->val) {
        return root;
      } else {
        return l ? l : r;
      }
    }
};
