class TreeAncestor {
public:
  TreeAncestor(int n, vector<int>& parent) {
    p.resize(n, vector<int>(16, -1));
    for (int i = 0; i < n; i++) {
      p[i][0] = parent[i];
    }
    for (int i = 1; i < 16; i++) {
      for (int j = 0; j < n; j++) {
        int tmp = p[j][i - 1];
        if (tmp != -1) p[j][i] = p[tmp][i - 1];
      }
    }
  }
    
  int getKthAncestor(int node, int k) {
    for (int i = 0; i < 16 && node != -1; i++) {
      if ((k >> i) & 1) {
        node = p[node][i];
      }
    }
    return node;
  }
private:
  vector<vector<int>> p;
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
