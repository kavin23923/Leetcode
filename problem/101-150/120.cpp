class Solution {
public:
  int minimumTotal(vector<vector<int>>& triangle) {
    int deep = triangle.size();
    int res  = INT_MAX;
    
    for (int i = 1; i < deep; i++) {
      for (int j = 0; j <= i; j++) {
        if (j == 0) {
          triangle[i][j] += triangle[i - 1][j];
        } else if (j == i) {
          triangle[i][j] += triangle[i - 1][j - 1];
        } else {
          triangle[i][j] += min(triangle[i - 1][j], triangle[i - 1][j - 1]);
        }
      }
    }
    
    for (int i = 0; i < deep; i++) {
      res = min(triangle[deep - 1][i], res);
    }
    
    return res;
  }
};
