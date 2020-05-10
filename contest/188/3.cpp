class Solution {
public:
  int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
    int found = 0;
    vector<vector<int>> edge(n);
    for (vector<int>& v : edges) {
      edge[v[0]].push_back(v[1]);
    }
    int res = dfs(0, edge, hasApple, &found);
    return found == 0 ? 0 : res;
  }
  
  int dfs(int now, vector<vector<int>>& edge, vector<bool>& hasApple, int *found) {
    if (hasApple[now]) (*found)++;
    int cost = 0;
    for (int i = 0; i < edge[now].size(); i++) {
      int pre = *found;
      int tmp_cost = dfs(edge[now][i], edge, hasApple, found) + 2;
      if (pre != *found) {
        cost += tmp_cost;
      }
    }
    return cost;
  }
};
