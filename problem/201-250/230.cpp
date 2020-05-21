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
  int kthSmallest(TreeNode* root, int k) {
    stack<TreeNode*> node;
    
    while (root || !node.empty()) {
      while (root) {
        node.push(root);
        root = root->left;
      }
      root = node.top();
      node.pop();
      if (--k == 0) return root->val;
      root = root->right;
    }
    
    return -1;
  }
};

/**
 * Can solve it using inorder traverse, too.
