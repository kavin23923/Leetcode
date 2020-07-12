class Solution {
public:
  double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
    vector<double> success(n, 0);
    vector<vector<pair<int, double>>> edge(n);
    queue<int> node;
    
    for (int i = 0; i < edges.size(); i++) {
      edge[edges[i][0]].push_back(make_pair(edges[i][1], succProb[i]));
      edge[edges[i][1]].push_back(make_pair(edges[i][0], succProb[i]));
    }
    
    success[start] = 1;
    node.push(start);
    
    while (!node.empty()) {
      int now = node.front();
      node.pop();
      for (auto &p : edge[now]) {
        if (success[now] * p.second > success[p.first]) {
          success[p.first] = success[now] * p.second;
          node.push(p.first);
        }
      }
    }
    
    return success[end];
  }
};
