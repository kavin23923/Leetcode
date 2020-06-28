class Solution {
public:
  vector<string> findItinerary(vector<vector<string>>& tickets) {
    unordered_map<string, multiset<string>> edge;
    vector<string> res;
    string start = "JFK";
    
    for (auto & t : tickets) {
      edge[t[0]].insert(t[1]);
    }
    
    dfs(edge, start, res);
    reverse(res.begin(), res.end());
    return res;
  }
  
  void dfs(unordered_map<string, multiset<string>> &edge, string &now, vector<string> &res) {
    while(edge[now].size() > 0) { // can't use for loop, as the element can be modified by another dfs
      string tmp = *edge[now].begin();
      edge[now].erase(edge[now].begin());
      dfs(edge, tmp, res);
    }
    res.push_back(now);
  }
};

/**
 * Solve it using topological sort
*/
