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
class FindElements {
public:
  FindElements(TreeNode* root) {
    my_root = root;
    cleanTree(my_root, 1);
  }
    
  bool find(int target) {
    target++;
    TreeNode* tmp = my_root;
    stack<int> digit = intToBinary(target);
    while (!digit.empty()) {
      int now = digit.top();
      digit.pop();
      if ((now == 0 && !tmp->left) || (now == 1 && !tmp->right)) {
        return false;
      }
      tmp = now ? tmp->right : tmp->left;
    }
    return true;;
  }
  
private:
  TreeNode* my_root;
  void cleanTree(TreeNode* root, int value) {
    if (!root) return;
    root->val = value;
    cleanTree(root->left, 2 * value);
    cleanTree(root->right, 2 * value + 1);
  }
  
  stack<int> intToBinary(int value) {
    stack<int> tmp;
    while (value > 0) {
      tmp.push(value & 1);
      value >>= 1;
    }
    tmp.pop();
    return tmp;
  }
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
