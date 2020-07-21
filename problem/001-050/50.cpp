class Solution {
public:
  double myPow(double x, int n) {
    if (n == 0) {
      return 1;
    } 
    double half = myPow(x, n / 2);
    if (n & 1) {
      return n < 0 ? 1 / x * half * half: x * half * half; 
    } else {
      return half * half;
    }
  }
};
