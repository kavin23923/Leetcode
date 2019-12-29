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
  vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
    vector<int> tree1;
    vector<int> tree2;
    vector<int> res;
    int now1 = 0;
    int now2 = 0;
    int i;
    
    inorder(root1, tree1);
    inorder(root2, tree2);
    
    while (now1 < tree1.size() && now2 < tree2.size()) {
      if (tree1[now1] < tree2[now2]) {
        res.push_back(tree1[now1++]);
      } else {
        res.push_back(tree2[now2++]);
      }
    }
    
    if (now1 < tree1.size()) {
      for (i = now1; i < tree1.size(); i++) {
        res.push_back(tree1[i]);
      }
    } else {
      for (i = now2; i < tree2.size(); i++) {
        res.push_back(tree2[i]);
      }
    }
    
    return res;
  }
  
  void inorder(TreeNode* root, vector<int>& tree) {
    if (!root) return;
    inorder(root->left, tree);
    tree.push_back(root->val);
    inorder(root->right, tree);
  }
};