class Solution {
public:
  vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
    vector<int> count(26);
    vector<vector<int>> edge(n);
    vector<bool> visit(n, false);
    vector<int> res(n);
    
    for (auto &v : edges) {
      edge[v[0]].push_back(v[1]);
      edge[v[1]].push_back(v[0]);
    }
    
    dfs(edge, res, visit, labels, 0);
    
    return res;
  }
  
  vector<int> dfs(vector<vector<int>>& edge, vector<int>& res, vector<bool> &visit, string &labels, int now) {
    vector<int> count(26);
    visit[now] = true;
    for(int i : edge[now]) {
      if (!visit[i]) {
        vector<int> tmp = dfs(edge, res, visit, labels, i);
        for (int i = 0; i < 26; i++) {
          count[i] += tmp[i];
        }
      }
    }
    count[labels[now] - 'a']++;
    res[now] = count[labels[now] - 'a'];
    return count;
  }
};
