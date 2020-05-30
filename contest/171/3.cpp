class Solution {
public:
  int makeConnected(int n, vector<vector<int>>& connections) {
    if (connections.size() < n - 1) return -1;
    vector<vector<int>> conn(n);
    vector<int> state(n, -1);
    int now = 0;
    
    for (auto c : connections) {
      conn[c[0]].push_back(c[1]);
      conn[c[1]].push_back(c[0]);
    }
    
    for (int i = 0; i < n; i++) {
      if (state[i] == -1) {
        dfs(i, conn, state, now++);
      }
    }
    
    return now - 1;
  }
  
  void dfs(int target, vector<vector<int>> &conn, vector<int> &state, int now) {
    state[target] = now;
    for (int i = 0; i < conn[target].size(); i++) {
      if (state[conn[target][i]] == -1) {
        dfs(conn[target][i], conn, state, now);
      }
    }
  }
};
