class Solution {
public:
  int findKthNumber(int m, int n, int k) {
    int l = 1, r = m * n, mid;
    int num;
    
    while (l < r) {
      mid = l + (r - l) / 2;
      num = countNum(mid, m, n);
      if (num < k) {
        l = mid + 1;
      } else {
        r = mid;
      }
    }
    return l;
  }
  
  int countNum(int target, int m, int n) {
    int num = 0, j;
    for (int i = 1; i <= m; i++) {
      num += min(n, target / i);
    }
    return num;
  }
};
