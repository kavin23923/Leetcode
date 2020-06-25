/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
  Node* connect(Node* root) {
    Node* parent = NULL;
    return myConnect(root, parent);
  }
  
  Node* myConnect(Node* root, Node* parent) {
    if (!root) return root;
    if (parent) {
      if (root == parent->left) {
        root->next = parent->right;
      } else if (parent->next){
        root->next = parent->next->left;
      }
    }
    root->left = myConnect(root->left, root);
    root->right = myConnect(root->right, root);
    return root;
  }
};
