class Solution {
public:
  int combinationSum4(vector<int>& nums, int target) {
    int size = nums.size();
    vector<unsigned int> dp(target + 1);
    dp[0] = 1;
    
    for (int i = 1; i <= target; i++) {
      for (int j = 0; j < size; j++) {
        if (nums[j] <= i) {
          dp[i] += dp[i - nums[j]];
        }
      }
    }
    
    return dp[target];
  }
};
