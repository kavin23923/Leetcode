class Solution {
public:
  vector<int> luckyNumbers (vector<vector<int>>& matrix) {
    vector<int> res;
    int m = matrix.size(), n = matrix[0].size();
    vector<int> row(m, INT_MAX);
    vector<int> col(n, INT_MIN);
    
    for (int i = 0; i < m; i++) {
      for (int j = 0; j < n; j++) {
        row[i] = min(row[i], matrix[i][j]);
        col[j] = max(col[j], matrix[i][j]);
      }
    }
    
    unordered_set<int> tmp;
    for (int i = 0; i < m; i++) {
      tmp.insert(row[i]);
    }
    for (int i = 0; i < n; i++) {
      if (tmp.find(col[i]) != tmp.end()) {
        res.push_back(col[i]);
      }
    }
    
    return res;
  }
};
