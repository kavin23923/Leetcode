class Solution {
public:
  int minCostClimbingStairs(vector<int>& cost) {
    int size = cost.size();
    vector<int> dp(size + 1, INT_MAX);
    dp[0] = 0;
    dp[1] = 0;
    
    for (int i = 0; i < size; i++) {
      dp[i + 1] = min(dp[i + 1], dp[i] + cost[i]);
      if (i + 2 <= size) {
        dp[i + 2] = dp[i] + cost[i];
      }
    }
    
    return dp[size];
  }
};
