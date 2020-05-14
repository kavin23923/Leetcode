class Solution {
public:
  int singleNonDuplicate(vector<int>& nums) {
    int l = 0, r = nums.size() - 1, m;
    while (l < r) {
      m = l + (r - l) / 2;
      if (nums[m] == nums[m ^ 1]) {
        l = m + 1;
      } else {
        r = m;
      }
    }
    return nums[l];
  }
};
/**
 * Use the xor operator to define the target node:
 * 1. if m is odd, then check m - 1
 * 2. if m is even, then check m + 1
 * The update strategy is the same. If m and target are the same, then the answer will be the right side.
 * Otherwise, it is on the left side.
 */
