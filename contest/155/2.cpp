class Solution {
public:
  int nthUglyNumber(int n, int a, int b, int c) {
    int l = 0, r = 1e9 * 2, m;
    int count;
    long long ab = lcm((long long)a, (long long)b);
    long long bc = lcm((long long)b, (long long)c);
    long long ac = lcm((long long)a, (long long)c);
    long long abc = lcm(ab, (long long)c);
    
    while (l < r) {
      m = l + (r - l) / 2;
      count = m / a + m / b + m / c - m / ab - m / bc - m / ac + m / abc;
      if (count < n) {
        l = m + 1;
      } else {
        r = m;
      }
    }
    
    return l;
  }
  
  long long lcm(long long a, long long b) {
    return a * b / gcd(a, b);
  }
  
  long long gcd(long long a, long long b) {
    return b == 0 ? a : gcd(b, a % b);
  }
};

// f(n): # of ugly number <= n
// f(n) = #a + #b + #c - #ac - #ab - #bc + #abc
