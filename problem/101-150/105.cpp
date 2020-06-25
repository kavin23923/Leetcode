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
  TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return build(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1);
  }
  
  TreeNode* build(vector<int>& preorder, int pl, int pr, vector<int>& inorder, int il, int ir) {
    if (pl > pr) return NULL;
    TreeNode* root = new TreeNode(preorder[pl]);
    int i;
    for (i = il; i <= ir; i++) {
      if (inorder[i] == preorder[pl]) break;
    }
    root->left = build(preorder, pl + 1, pl + i - il, inorder, il, i - 1); 
    root->right = build(preorder, pr- ir + i + 1, pr, inorder, i + 1, ir);
    return root;
  }
};
