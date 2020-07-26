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
  int countPairs(TreeNode* root, int distance) {
    int pair = 0;
    dfs(root, distance, &pair);
    return pair;
  }
  
  vector<int> dfs(TreeNode* root, int distance, int *pair) {
    if (!root) {
      return {};
    } else if (!root->left && !root->right) {
      return {1};
    }
    
    vector<int> res;
    vector<int> l = dfs(root->left, distance, pair);
    vector<int> r = dfs(root->right, distance, pair);
    int r_bound = r.size() - 1;
    
    for (int i = 0; i < l.size(); i++) {
      while (r_bound >= 0 && l[i] + r[r_bound] > distance) {
        r_bound--;
      }
      *pair += r_bound + 1;
    }
    
    for (int i = 0; i < l.size(); i++) {
      if (l[i] + 1 < distance) {
        res.push_back(l[i] + 1);
      }
    }
    for (int i = 0; i < r.size(); i++) {
      if (r[i] + 1 < distance) {
        res.push_back(r[i] + 1);
      }
    }
    sort(res.begin(), res.end());
    return res;
  }
};
