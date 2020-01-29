class Solution {
public:
  int triangleNumber(vector<int>& nums) {
    int res = 0;
    int i, l, r, size = nums.size();

    sort(nums.begin(), nums.end());
    for (i = size - 1; i >= 2; i--) {
      l = 0;
      r = i - 1;
      while (l < r) {
        if (isTriangle(nums[l], nums[r], nums[i])) {
          res += r - l;
          r--;
        } else {
          l++;
        }
      }
    }
    return res;
  }

  bool isTriangle(int small, int medien, int large) {
    if (small + medien > large) {
      return true;
    } else {
      return false;
    }
  }
};

/**
 * The outer for loop must traverse from large to small number.
 * Otherwise you do not know l and r which one should be moved (both are possible).
 */
