class Solution {
public:
  vector<int> getRow(int rowIndex) {
    vector<int> dp(rowIndex + 1, 0);
    int i, j, pre, tmp;
    dp[0] = 1;
    
    for (i = 1; i <= rowIndex; i++){
      pre = dp[0];
      for (j = 1; j <= i; j++) {
        tmp = dp[j];
        dp[j] += pre;
        pre = tmp;
      }
    }
    return dp;
  }
};
