class Solution {
public:
  int searchInsert(vector<int>& nums, int target) {
    int l = 0, r = nums.size(), m;
    
    while (l < r) {
      m = l + (r - l) / 2;
      if (nums[m] >= target) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    return r;
  }
};
