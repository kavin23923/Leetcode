class Solution {
public:
  int minReorder(int n, vector<vector<int>>& connections) {
    int res = 0;
    vector<unordered_set<int>> out(n);
    vector<vector<int>> edge(n); 
    vector<bool> visit(n, false);
    queue<int> city;
    city.push(0);
    
    for(auto c : connections) {
      out[c[0]].insert(c[1]);
      edge[c[0]].push_back(c[1]);
      edge[c[1]].push_back(c[0]);
    }
    
    while (!city.empty()) {
      int now = city.front();
      city.pop();
      visit[now] = true;
      for (int i = 0; i < edge[now].size(); i++) {
        if (!visit[edge[now][i]]) {
          city.push(edge[now][i]);
          if (out[edge[now][i]].find(now) == out[edge[now][i]].end()) {
            res++;
          }
        }
      }
    }
    return res;
  }
};
