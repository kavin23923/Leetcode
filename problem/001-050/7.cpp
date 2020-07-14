class Solution {
public:
  int reverse(int x) {
    int res = 0, sign = x > 0 ? 1 : -1;
    
    x = abs(x);
    while (x > 0) {
      if (sign > 0 && (res > INT_MAX / 10 || (res == INT_MAX / 10 && x % 10 >= 8))) {
        return 0;
      } else if (sign < 0 && (res > INT_MAX / 10 || (res == INT_MAX / 10 && x % 10 == 9))) {
        return 0;
      }
      res = res * 10 + x % 10;
      x /= 10;
    }
    
    return res * sign;
  }
};
