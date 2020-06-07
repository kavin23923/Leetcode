class Solution {
public:
  int numberOfArithmeticSlices(vector<int>& A) {
    int size = A.size();
    int res = 0;    
    vector<int> dp(size);
    
    if (A.size() < 3) return 0;
    dp[1] = 0;
    for (int i = 2; i < size; i++) {
      if (A[i - 2] - A[i - 1] == A[i - 1] - A[i]) {
        dp[i] = dp[i - 1] + 1;
        res += dp[i];
      } else {
        dp[i] = 0;
      }
    }
    
    return res;
  }
};
