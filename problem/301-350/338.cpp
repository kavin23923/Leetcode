class Solution {
public:
  vector<int> countBits(int num) {
    vector<int> dp(num + 1);
    int offset = 1;
    
    for (int i = 1; i <= num; i++) {
      dp[i] = dp[i - offset] + 1;
      if (offset * 2 == i + 1) {
        offset <<= 1;
      }
    }
    
    return dp;
  }
};
