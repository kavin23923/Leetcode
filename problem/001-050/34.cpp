class Solution {
public:
  vector<int> searchRange(vector<int>& nums, int target) {
    vector<int> res(2, -1);
    int l = 0, r = nums.size() - 1, m;
    
    while (l < r) {
      m = l + (r - l) / 2;
      if (nums[m] >= target) {
        r = m;
      } else {
        l= m + 1;
      }
    }
    if (nums.size() == 0 || nums[l] != target) return res;
    res[0] = l;
    
    r = nums.size();
    while (l < r) {
      m = l + (r - l) / 2;
      if (nums[m] > target) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    res[1] = r - 1;
    
    return res;
  }
};
