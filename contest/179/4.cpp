class Solution {
public:
  double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
    double res = 1;
    vector<vector<int>> edge(n+1);
    vector<int> start = {1};
    vector<int> path;
    queue<pair<int, vector<int>>> round;
    
    for (int i = 0; i < n - 1; i++) {
      int from = edges[i][0];
      int to = edges[i][1];
      edge[from].push_back(to);
      edge[to].push_back(from);
    }
    
    round.push(make_pair(1, start));
    while (!round.empty()) {
      int node = round.front().first;
      path = round.front().second;
      unordered_set<int> exist(path.begin(), path.end());
      round.pop();
      if (exist.find(target) != exist.end()) {
        break;
      }
      for (int i = 0; i < edge[node].size(); i++) {
        if (exist.find(edge[node][i]) == exist.end()) {
          vector<int> tmp = path;
          tmp.push_back(edge[node][i]);
          round.push(make_pair(edge[node][i], tmp));
        }
      }
    }
    
    if(path.size() - 1 > t) return 0;
    
    for (int i = 0; i < path.size() && t > 0; i++) {
      if (i == path.size() - 1) {
        if ((path[i] == 1 && edge[path[i]].size() == 0) || (path[i] != 1 && edge[path[i]].size() == 1)) {
          t = 0;
        }
        break;
      }
      int num = i == 0 ? edge[path[i]].size() : edge[path[i]].size() - 1;
      res /= num;
      t--;
    }
    
    return t == 0 ? res : 0;
  }
};
