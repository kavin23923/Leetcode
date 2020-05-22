class Solution {
public:
  int minSubArrayLen(int s, vector<int>& nums) {
    int l = 0, r = 0, size = nums.size();
    int res = INT_MAX, sum = 0;
    
    while (r < size) {
      while (r < size && sum < s) {
        sum += nums[r++];
      }

      while (l <= r && sum >= s) {
        res = min(res, r - l);
        sum -= nums[l++];
      }
    }
    
    return res == INT_MAX ? 0 : res;
  }
};
