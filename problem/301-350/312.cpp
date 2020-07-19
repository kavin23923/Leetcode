class Solution {
public:
  int maxCoins(vector<int>& nums) {
    int n = nums.size();
    vector<int> coin(n + 2);
    vector<vector<int>> dp(n + 2, vector<int>(n + 2));
    
    for (int i = 0; i < n + 2; i++) {
      coin[i] = i == 0 || i == n + 1 ? 1 : nums[i - 1];
    }
    
    return dfs(coin, dp, 1, n);
  }
  
  int dfs(vector<int> &coin, vector<vector<int>> &dp, int left, int right) {
    if (left > right) {
      return 0;
    } else if (dp[left][right] > 0) {
      return dp[left][right];
    }
    
    for (int i = left; i <= right; i++) {
      dp[left][right] = max(dp[left][right], dfs(coin, dp, left, i - 1) + dfs(coin, dp, i + 1, right) + coin[left - 1] * coin[i] * coin[right + 1]);
    }
    return dp[left][right];
  }
};
