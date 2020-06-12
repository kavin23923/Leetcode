class Solution {
public:
  vector<int> singleNumber(vector<int>& nums) {
    vector<int> res(2);
    int size = nums.size(), tmp = 0;
    
    for (int i = 0; i < size; i++) {
      tmp ^= nums[i];
    }
    tmp &= -tmp;
    for (int i = 0; i < size; i++) {
      if (nums[i] & tmp) {
        res[0] ^= nums[i];
      } else {
        res[1] ^= nums[i];
      }
    }
    return res;
  }
};
