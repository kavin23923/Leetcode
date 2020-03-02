class Solution {
public:
  bool validateBinaryTreeNodes(int n, vector<int>& leftChild, vector<int>& rightChild) {
    unordered_set<int> nodes;
    for (int i = 0; i < n; i++) {
      nodes.insert(i);
    }
    for (int i = 0; i < n; i++) {
      if (leftChild[i] != -1) {
        if (nodes.find(leftChild[i]) == nodes.end()) {
          return false;
        }
        nodes.erase(leftChild[i]);
      }
    }
    for (int i = 0; i < n; i++) {
      if (rightChild[i] != -1) {
        if (nodes.find(rightChild[i]) == nodes.end()) {
          return false;
        }
        nodes.erase(rightChild[i]);
      }
    }
    return nodes.size() == 1;
  }
  
};
