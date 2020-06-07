class Solution {
public:
  bool canPartition(vector<int>& nums) {
    int half = target(nums), size = nums.size();
    if (half == -1) return false;
    vector<bool> dp(half + 1, false);
    dp[0] = true;
    
    for (int i = 0; i < size; i++) {
      for (int j = half; j >= nums[i]; j--) {
        dp[j] = dp[j] || dp[j - nums[i]]; 
      }
    }
    
    return dp[half];
  }
  
  int target(vector<int>& nums) {
    int sum = 0;
    int size = nums.size();
    for (int i = 0; i < size; i++) {
      sum += nums[i];
    }
    return sum % 2 == 0 ? sum / 2 : -1;
  }
};
