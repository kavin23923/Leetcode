class Solution {
public:
  int maxProduct(vector<int>& nums) {
    int size = nums.size();
    sort(nums.begin(), nums.end());
    return max((nums[0] - 1) * (nums[1] - 1), (nums[size - 2] - 1) * (nums[size - 1] - 1));
  }
};
