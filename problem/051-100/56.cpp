class Solution {
public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> res;
    auto cmp = [](vector<int>& a, vector<int>& b) {
      return a[0] < b[0]; 
    };
    int i, size = intervals.size(), last;
    
    sort(intervals.begin(), intervals.end(), cmp);
    
    for (i = 0; i < size; i++) {
      last = res.size() - 1;
      if (res.size() == 0 || intervals[i][0] > res[last][1]) {
        res.push_back(intervals[i]);
      } else {
        res[last][1] = max(intervals[i][1], res[last][1]);
      }
    }
    return res;
  }
};
