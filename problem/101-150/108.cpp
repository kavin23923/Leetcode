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
  TreeNode* sortedArrayToBST(vector<int>& nums) {
    TreeNode* root = buildTree(nums, 0, nums.size() - 1);
    return root;
  }
  
  TreeNode* buildTree(vector<int>& nums, int start, int end) {
    if (start > end) {
      return NULL;
    } else if (start == end) {
      return new TreeNode(nums[start]);
    }
    
    int mid = start + (end - start) / 2;
    TreeNode* root = new TreeNode(nums[mid]);
    root->left = buildTree(nums, start, mid - 1);
    root->right = buildTree(nums, mid + 1, end);
    return root;
  }
};
