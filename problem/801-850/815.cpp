class Solution {
public:
  int numBusesToDestination(vector<vector<int>>& routes, int S, int T) {
    int res = 0;
    unordered_map<int, vector<int>> edge;
    queue<int> stop;
    unordered_set<int> exist;
    
    for (int i = 0; i < routes.size(); i++) {
      for (int r : routes[i]) {
        edge[r].push_back(i);
      }
    }
    
    stop.push(S);
    exist.insert(S);
    while(!stop.empty()) {
      int size = stop.size();
      for (int i = 0; i < size; i++) {
        int now = stop.front();
        stop.pop();
        if (now == T) return res;
        for (auto e : edge[now]) {
          for (int j = 0; j < routes[e].size(); j++) {
            if (exist.find(routes[e][j]) == exist.end()) {
              exist.insert(routes[e][j]);
              stop.push(routes[e][j]);
            }
          }
          routes[e].clear();
        }
      }
      res++;
    }
    
    return -1;
  }
};
