class Solution {
public:
  bool canJump(vector<int>& nums) {
    int far = 0, size = nums.size();
    
    for (int i = 0; i < size; i++) {
      if (far < i) {
        return false;
      }
      far = max(far, i + nums[i]);
    }
    return true;
  }
};
