class Solution {
public:
  int rob(vector<int>& nums) {
    int size = nums.size();
    if (size == 0) {
      return 0;
    } else if (size == 1) {
      return nums[0];
    } else {
      return max(robRange(nums, 0, size - 1), robRange(nums, 1, size));
    }
  }
  
  int robRange(vector<int>& nums, int start, int end) {
    int pre = 0, prepre = 0, tmp;
    for (int i = start; i < end; i++) {
      tmp = pre;
      pre = max(prepre + nums[i], pre);
      prepre = tmp;
    }
    return max(pre, prepre);
  }
};
