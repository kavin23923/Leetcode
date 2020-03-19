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
  TreeNode* balanceBST(TreeNode* root) {
    vector<TreeNode*> nodes;
    inorder(root, nodes);
    TreeNode* new_root = balance(nodes, 0, nodes.size() - 1);
    return new_root;
  }
  
  TreeNode* balance(vector<TreeNode*>& nodes, int start, int end) {
    if (start > end) return NULL;
    int mid = start + (end - start) / 2;
    TreeNode* root =  nodes[mid];
    root->left = balance(nodes, start, mid - 1);
    root->right = balance(nodes, mid + 1, end);
    return root;
  }
  
  void inorder(TreeNode* root, vector<TreeNode*>& nodes) {
    if (!root) return;
    inorder(root->left, nodes);
    nodes.push_back(root);
    inorder(root->right, nodes);
  }
};
