class Solution {
public:
  int totalHammingDistance(vector<int>& nums) {
    int res = 0;
    int size = nums.size();
    int round;
    
    for (int i = 0; i < 32; i++) {
      round = 0;
      for (int j = 0; j < size; j++) {
        round += nums[j] & 1;
        nums[j] >>= 1;
      }
      res += (size - round) * round;
    }
    
    return res;
  }
};
