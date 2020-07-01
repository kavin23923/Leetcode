class Solution {
public:
  int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
    deque<pair<int, int>> point;
    int res = INT_MIN;
    
    for (auto p : points) {
      while (!point.empty() && p[0] - point.front().second > k) {
        point.pop_front();
      }
      if (!point.empty()) res = max(res, point.front().first + p[0] + p[1]);
      while (!point.empty() && point.back().first <= p[1] - p[0]) {
        point.pop_back();
      }
      point.push_back(make_pair(p[1] - p[0], p[0]));
    }
    
    return res;
  }
};
