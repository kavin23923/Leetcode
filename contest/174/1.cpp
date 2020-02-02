class Solution {
public:
  vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
    int m = mat.size();
    int n = mat[0].size();
    auto cmp = [](pair<int, int>& a, pair<int, int>& b) {
      return a.second > b.second || (a.second == b.second && a.first > b.first);
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> row(cmp);
    vector<int> res;
    
    for (int i = 0; i < m; i++) {
      int count = 0;
      for (int j = 0; j < n; j++) {
        if (mat[i][j]) count++;
      }
      row.push(make_pair(i, count));
    }
    
    for (int i = 0; i < k; i++) {
      res.push_back(row.top().first);
      row.pop();
    }
    return res;
  }
};
