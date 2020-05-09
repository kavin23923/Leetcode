/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
  vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> level;
    queue<Node*> target;
    Node* tmp;
    
    if (root) target.push(root);
    while (target.size() > 0) {
      int size = target.size();
      vector<int> now;
      for (int i = 0; i < size; i++) {
        tmp = target.front();
        target.pop();
        now.push_back(tmp->val);
        for (Node* n : tmp->children) {
          target.push(n);
        }
      }
      level.push_back(now);
    }
    
    return level;
  }
};
