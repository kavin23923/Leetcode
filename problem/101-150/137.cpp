class Solution {
public:
  int singleNumber(vector<int>& nums) {
    int one = 0, two = 0;
    int size = nums.size();
    int common;
    
    for (int i = 0; i < size; i++) {
      two |= one & nums[i];
      one ^= nums[i];
      common = ~(two & one); // used to erase three times number
      two &= common;
      one &= common;
    }
    return one;
  }
};
