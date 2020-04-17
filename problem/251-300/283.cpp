class Solution {
public:
  void moveZeroes(vector<int>& nums) {
    int now = 0, size = nums.size();
    for (int i = 0; i < size; i++) {
      if (nums[i] != 0) {
        nums[now++] = nums[i];
      }
    }
    for (int i = now; i < size; i++) {
      nums[i] = 0;
    }
  }
};
