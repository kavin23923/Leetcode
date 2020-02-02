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
  int maxProduct(TreeNode* root) {
    vector<int> candidates;
    int total = traverse(root, candidates);
    int target = total / 2;
    int diff = abs(candidates[0] - target);
    int index = 0;
    
    for (int i = 1; i < candidates.size(); i++) {
      int tmp = abs(candidates[i] - target);
      if (tmp < diff) {
        diff = tmp;
        index = i;
      }
    }
    
    long long res = (long long) candidates[index] * (total - candidates[index]) % 1000000007;
    
    return (int) res;
  }
  
  int traverse(TreeNode* root, vector<int>& candidates) {
    if (!root) return 0;
    int l = traverse(root->left, candidates);
    int r = traverse(root->right, candidates);
    int sum = l + r + root->val;
    candidates.push_back(sum);
    return sum;
  }
};
