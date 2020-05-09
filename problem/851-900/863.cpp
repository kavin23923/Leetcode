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
  vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
    unordered_map<TreeNode*, TreeNode*> parent;
    unordered_set<TreeNode*> visit;
    vector<int> res;
    queue<TreeNode*> node;
    
    dfs(root, parent);
    node.push(target);
    while (!node.empty() && K > 0) {
      int size = node.size();
      for (int i = 0; i < size; i++) {
        TreeNode* now = node.front();
        node.pop();
        visit.insert(now);
        if (now->left && visit.find(now->left) == visit.end()) node.push(now->left);
        if (now->right && visit.find(now->right) == visit.end()) node.push(now->right);
        if (parent.find(now) != parent.end() && visit.find(parent[now]) == visit.end()) node.push(parent[now]);
      }
      K--;
    }
    
    while (!node.empty()) {
      res.push_back(node.front()->val);
      node.pop();
    }
    
    return res;
  }
  
  void dfs(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& parent) {
    if (!root) return;
    if (root->left) {
      parent[root->left] = root;
      dfs(root->left, parent);
    }
    if (root->right) {
      parent[root->right] = root;
      dfs(root->right, parent);
    }
  }
};

/**
 * Find the parent of each node first. Then use BFS. Use a set to record all visited nodes.
 */

