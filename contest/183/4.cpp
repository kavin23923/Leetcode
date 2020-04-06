class Solution {
public:
  string stoneGameIII(vector<int>& stoneValue) {
    int sum, size = stoneValue.size();
    vector<int> dp(size + 1, 0);
    
    for (int i = size - 1; i >= 0; i--) {
      sum = 0;
      for (int j = 0; j < 3 && j + i < size; j++) {
        sum += stoneValue[i + j];
        dp[i] = j == 0 ? sum - dp[i + j + 1] : max(dp[i], sum - dp[i + j + 1]);
      }
    }
    
    if (dp[0] > 0) {
      return "Alice";
    } else if (dp[0] < 0) {
      return "Bob";
    } else {
      return "Tie";
    }
  }
};
