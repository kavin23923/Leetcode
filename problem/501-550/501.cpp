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
  vector<int> findMode(TreeNode* root) {
    vector<int> res;
    int pre = INT_MAX;
    int freq = 0;
    int now = 0;
    inorder(res, root, &pre, &freq, &now);
    return res;
  }
  
  void inorder(vector<int> &res, TreeNode *root, int *pre, int *freq, int *now) {
    if (!root) return;
    
    inorder(res, root->left, pre, freq, now);
    
    if (*pre == root->val) {
      *now = *now + 1;
    } else {
      *now = 1;
    }
    if (*now > *freq) {
      *freq = *now;
      res.resize(0);
      res.push_back(root->val);
    } else if (*now == *freq) {
      res.push_back(root->val);
    }
    *pre = root->val;
    
    inorder(res, root->right, pre, freq, now);
  }
};

/**
 * 1. '*now++' causes segmentation fault. Because '++' will do first, then '*'
 * 2. TreeNode *pre can't store the previod node
 */ 
