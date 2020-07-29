class Solution {
public:
  int firstMissingPositive(vector<int>& nums) {
    int n = nums.size();
    int now = 0;
    
    while (now < n) {
      if (nums[now] > 0 && nums[now] < n && nums[now] != nums[nums[now]]) {
        swap(nums[now], nums[nums[now]]);
      } else {
        now++;
      }
    }
    
    for (int i = 1; i < n; i++) {
      if (nums[i] != i) return i;
    }
    
    return n == 0 || nums[0] == n ? n + 1 : n;
  }
};
