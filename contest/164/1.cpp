class Solution {
public:
  int minTimeToVisitAllPoints(vector<vector<int>>& points) {
    int size = points.size();
    int res = 0;
    int dx, dy;
    
    for (int i = 1; i < size; i++) {
      dx = abs(points[i][0] - points[i - 1][0]);
      dy = abs(points[i][1] - points[i - 1][1]);
      res += max(dx, dy);
    }
    
    return res;
  }
};
