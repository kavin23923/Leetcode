class Solution {
public:
  int arrangeCoins(int n) {
    int l = 1, r = n, m;
    long long count;
    
    while (l <= r) {
      m = l + (r - l) / 2;
      count = (long long)(1 + m) * m / 2;
      if (count == n) {
        return m;
      } else if (count < n) {
        l = m + 1;
      } else {
        r = m - 1;
      }
    }
    return r;
  }
};
