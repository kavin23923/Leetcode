class Solution {
public:
  int maximumSum(vector<int>& arr) {
    int n = arr.size();
    int now, sum, res = INT_MIN;
    vector<int> prefix(n);
    vector<int> suffix(n);
    
    now = 0;
    for (int i = 0; i < n; i++) {
      now = max(arr[i], now + arr[i]);
      res = max(res, now);
      prefix[i] = now;
    }
    
    now = 0;
    for (int i = n - 1; i >= 0; i--) {
      now = max(arr[i], now + arr[i]);
      suffix[i] = now;
    }
    
    for (int i = 1; i < n -1; i++) {
      res = max(res, prefix[i - 1] + suffix[i + 1]);
    }
    
    return res;
  }
};
