class Solution {
public:
  int wiggleMaxLength(vector<int>& nums) {
    int size = nums.size();
    vector<int> incr(size);
    vector<int> decr(size);
    
    if(size == 0) return 0;
    for (int i = 1; i < size; i++) {
      incr[i] = incr[i - 1];
      decr[i] = decr[i - 1];
      if (nums[i] > nums[i - 1]) {
        incr[i] = decr[i - 1] + 1;
      } else if (nums[i] < nums[i - 1]) {
        decr[i] = incr[i - 1] + 1;
      }
    }
    
    return max(incr[size - 1], decr[size - 1]) + 1;
  }
};
