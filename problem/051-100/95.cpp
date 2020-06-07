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
  vector<TreeNode*> generateTrees(int n) {
    return n == 0 ? vector<TreeNode*>() : generate(1, n);
  }
  
  vector<TreeNode*> generate(int left, int right) {
    if (left > right) return {NULL};
    vector<TreeNode*> tmp;
    
    for (int i = left; i <= right; i++) {
      vector<TreeNode*> l = generate(left, i - 1);
      vector<TreeNode*> r = generate(i + 1, right);
      for (int a = 0; a < l.size(); a++) {
        for (int b = 0; b < r.size(); b++) {
          TreeNode* now = new TreeNode(i);
          now->left = l[a];
          now->right = r[b];
          tmp.push_back(now);
        }
      }
    }
    return tmp;
  }
};
