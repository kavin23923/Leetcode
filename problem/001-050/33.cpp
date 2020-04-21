class Solution {
public:
  int search(vector<int>& nums, int target) {
    int l = 0, r = nums.size() - 1, m;
    
    while (l <= r) {
      m = l + (r - l) / 2;
      if (nums[m] == target) {
        return m;
      } else if (nums[l] <= nums[m]) { // left sorted
        if (nums[l] <= target && target < nums[m]) {
          r = m - 1;
        } else {
          l = m + 1;
        }
      } else { // right sorted
        if (nums[m] < target && target <= nums[r]) {
          l = m + 1;
        } else {
          r = m - 1;
        }
      }
    }
    
    return -1;
  }
};
/**
 * 1. use l, m, r to check which half part is sorted, then update.
 * 2. nums[l] <= nums[m], must have the equal sign. Or for this case: [3, 1], (l,m,r) = (0,0,1), but m~r is not right sorted.
 */
