class Solution {
public:
  vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> res;
    int n = intervals.size(), now = 0;
    
    while (now < n && intervals[now][1] < newInterval[0]) {
      res.push_back(intervals[now++]);
    }
    while (now < n && intervals[now][0] <= newInterval[1]) {
      newInterval[0] = min(newInterval[0], intervals[now][0]);
      newInterval[1] = max(newInterval[1], intervals[now++][1]);
    }
    res.push_back(newInterval);
    while (now < n) {
      res.push_back(intervals[now++]);
    }
    return res;
  }
};
