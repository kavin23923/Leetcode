class Solution {
public:
  bool PredictTheWinner(vector<int>& nums) {
    int size = nums.size();
    vector<vector<int>> dp(size, vector<int>(size));
    
    for (int i = size - 2; i >= 0; i--) {
      for (int j = i + 1; j < size; j++) {
        dp[i][j] = max(nums[i] - dp[i + 1][j], nums[j] - dp[i][j - 1]);
      }
    }
    
    return dp[0][size - 1] >= 0;
  }
};
