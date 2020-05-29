class Solution {
public:
  int minTaps(int n, vector<int>& ranges) {
    int res = 0, end, far = 0;
    vector<pair<int, int>> range;
    
    for (int i = 0; i <= n; i++) {
      if (ranges[i] != 0) {
        range.push_back(make_pair(i - ranges[i], i + ranges[i]));
      }
    }
    sort(range.begin(), range.end());
      
    end = far;
    for (int i = 0; i <= range.size() && far < n; end = far, res++) {
      while (i < range.size() && range[i].first <= end) {
        far = max(far, range[i++].second);
      }
      if (end == far) {
        return -1;
      }
    }
    
    return res;
  }
};
