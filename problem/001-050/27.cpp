class Solution {
public:
  int removeElement(vector<int>& nums, int val) {
    int now = 0;
    int i, size = nums.size();

    for (i = 0; i < size; i++) {
      if (nums[i] != val) {
        nums[now++] = nums[i];
      }
    }
    return now;
  }
};
