class Solution {
public:
  int change(int amount, vector<int>& coins) {
    int size = coins.size();
    vector<vector<int>> dp(size + 1, vector<int>(amount + 1));
    
    dp[0][0] = 1;
    for (int i = 1; i <= size; i++) {
      dp[i][0] = 1;
      for (int j = 1; j <= amount; j++) {
        dp[i][j] = dp[i - 1][j] + (coins[i - 1] <= j ? dp[i][j - coins[i - 1]] : 0);
      }
    }
    
    return dp[size][amount];
  }
};
/**
 * Be careful of the dimension. If we swap the size and amount, the answer will be more than the correct one.
 */
