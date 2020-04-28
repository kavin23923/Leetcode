class Solution {
public:
  int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> count;
    int size = nums.size(), res = 0, sum = 0;
    
    count[0] = 1;
    
    for (int i = 0; i < size; i++) {
      sum += nums[i];
      res += count[sum - k];
      count[sum]++;
    }
    
    return res;
  }
};
/**
 * Should set count[0] = 1 first, or res will be some less than the real answer.
 * Example: [1], k = 1 -> the answer is 1. Put count[0]=1 first can let us count the number.
 */
