/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
  BSTIterator(TreeNode* root) {
    while (root) {
      node.push(root);
      root = root->left;
    }
  }

  /** @return the next smallest number */
  int next() {
    TreeNode* tmp = node.top();
    int res = tmp->val;
    
    node.pop();
    tmp = tmp->right;
    while (tmp) {
      node.push(tmp);
      tmp = tmp->left;
    }
    return res;
  }

  /** @return whether we have a next smallest number */
  bool hasNext() {
    return !node.empty();
  }

private: 
  stack<TreeNode*> node; 
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
