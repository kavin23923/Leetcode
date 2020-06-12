class Solution {
public:
  int integerReplacement(int n) {
    if (n == INT_MAX) return 32;
    int res = 0;
    while (n > 1) {
      if (n & 1) {
        if (n == 3 || ((n >> 1) & 1) == 0) {
          n--;
        } else {
          n++;
        }
      } else {
        n /= 2;
      }
      res++;
    }
    return res;
  }
};
