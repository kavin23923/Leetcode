class Solution {
public:
  string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
    int n = s.size();
    vector<vector<int>> edge(n);
    vector<bool> visit(n, false);
    
    for (auto &p : pairs) {
      edge[p[0]].push_back(p[1]);
      edge[p[1]].push_back(p[0]);
    }
      
    for (int i = 0; i < n; i++) {
      if (!visit[i]) {
        vector<int> idx;
        string tmp = "";
        dfs(s, edge, visit, tmp, idx, i);
        sort(tmp.begin(), tmp.end());
        sort(idx.begin(), idx.end());
        for (int j = 0; j < idx.size(); j++) {
          s[idx[j]] = tmp[j];
        }
      }
    }
    
    return s;
  }
  
  void dfs(string &s, vector<vector<int>> &edge, vector<bool>& visit, string &tmp, vector<int> &idx, int now) {
    visit[now] = true;
    tmp += s[now];
    idx.push_back(now);
    for (int i = 0; i < edge[now].size(); i++) {
      if (!visit[edge[now][i]]){
        dfs(s, edge, visit, tmp, idx, edge[now][i]);
      }
    }
  }
};
