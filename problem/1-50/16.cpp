class Solution {
public:
  int threeSumClosest(vector<int>& nums, int target) {
    int diff = INT_MAX, sum;
    int res;
    int i, l, r, size = nums.size(); 

    sort(nums.begin(), nums.end());
    for (i = 0; i < size - 2; i++) {
      l = i + 1;
      r = size - 1;
      while (l < r) {
        sum = nums[i] + nums[l] + nums[r];
        if (sum == target) {
          return target;
        } else {
          if (abs(sum - target) < diff) {
            diff = abs(sum - target);
            res = sum;
          }
          if (sum > target) {
            r--;
          } else {
            l++;
          }
        }
      }
    }
    return res;
  }
};
