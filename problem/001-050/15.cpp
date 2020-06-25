class Solution {
public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    vector<vector<int>> res;
    int n = nums.size(), now = 0;
    int l, r, sum;
    
    sort(nums.begin(), nums.end());
    while (now < n) {
      l = now + 1;
      r = n - 1;
      while (l < r) {
        sum = nums[now] + nums[l] + nums[r];
        if (sum == 0) {
          res.push_back({nums[now], nums[l++], nums[r--]});
          while (l < r && nums[l] == nums[l - 1]) l++;
          while (l < r && nums[r] == nums[r + 1]) r--;
        } else if (sum < 0) {
          l++;
        } else {
          r--;
        }
      }
      now++;
      while (now < n && nums[now] == nums[now - 1]) now++;
    }
    
    return res;
  }
};
