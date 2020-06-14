class Solution {
public:
  int oddCells(int n, int m, vector<vector<int>>& indices) {
    int res = 0, now;
    vector<int> row(n), col(m);
    
    for (int i = 0; i < indices.size(); i++) {
      row[indices[i][0]]++;
      col[indices[i][1]]++;
    }
    
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        now = row[i] + col[j];
        if (now & 1) res++;
      }
    }
    return res;
  }
};
