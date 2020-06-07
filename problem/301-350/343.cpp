class Solution {
public:
  int integerBreak(int n) {
    vector<int> dp = {0, 0, 1, 2};
    int product = 1;
    if (n <= 3) return dp[n];
    
    while (n > 0) {
      if (n <= 4) {
        product *= n;
        n = 0;
      } else {
        product *= 3;
        n -= 3;
      }
    }
    
    return product;
  }
};
