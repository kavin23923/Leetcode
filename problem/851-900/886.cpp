class Solution {
public:
  bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
    vector<int> group(N + 1, 0); // -1 and 1
    vector<vector<int>> dislike(N + 1);
    
    for (auto &v : dislikes) {
      dislike[v[0]].push_back(v[1]);
      dislike[v[1]].push_back(v[0]);
    }
    
    for (int i = 1; i<= N; i++) {
      if (group[i] == 0 && !dfs(group, dislike, i, 1)) {
        return false;
      }
    }
    return true;
  }
  
  bool dfs(vector<int> &group, vector<vector<int>> &dislike, int now, int g) {
    group[now] = g;
    for (int d : dislike[now]) {
      if (group[d] != 0 && group[d] == g) {
        return false;
      } else if (group[d] == 0 && !dfs(group, dislike, d, -g)) {
        return false;
      }
    }
    return true;
  }
};
