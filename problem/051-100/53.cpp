class Solution {
public:
  int maxSubArray(vector<int>& nums) {
    int size = nums.size(), res = INT_MIN;
    vector<int> dp(size + 1);
    dp[0] = -1;
    
    for (int i = 0; i < size; i++) {
      dp[i + 1] = max(nums[i], dp[i] + nums[i]);
      res = max(res, dp[i + 1]);
    }
    
    return res;
  }
};
