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
  bool findTarget(TreeNode* root, int k) {
    vector<int> node;
    inorderTraverse(node, root);
    
    int left = 0;
    int right = node.size() - 1;
    int sum;
    while (left < right) {
      sum = node[left] + node[right];
      if (sum == k) {
        return true;
      } else if (sum < k) {
        left++;
      } else {
        right--;
      }
    }
    
    return false;
  }
  
  void inorderTraverse(vector<int>& node, TreeNode* root) {
    if (!root) return;
    inorderTraverse(node, root->left);
    node.push_back(root->val);
    inorderTraverse(node, root->right);
  }
};

/** 
 * This approach uses the fact that the tree is BST, and the performance is better than using unordered_set
 */
