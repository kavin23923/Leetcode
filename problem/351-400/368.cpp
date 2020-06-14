class Solution {
public:
  vector<int> largestDivisibleSubset(vector<int>& nums) {
    int n = nums.size();
    int size = 0, index = -1;
    vector<int> dp(n, 1);
    vector<int> pre(n, -1);
    vector<int> res;
    
    sort(nums.begin(), nums.end());
    for (int i = 0; i < n; i++) {
      for (int j = i - 1; j >= 0; j--) {
        if (nums[i] % nums[j] == 0 && dp[j] + 1 > dp[i]) {
          dp[i] = dp[j] + 1;
          pre[i] = j;
        }
      }
      if (dp[i] > size) {
        size = dp[i];
        index = i;
      }
    }
    
    while (index != -1) {
      res.push_back(nums[index]);
      index = pre[index];
    }
    
    return res;
  }
};
