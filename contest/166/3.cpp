class Solution {
public:
  int smallestDivisor(vector<int>& nums, int threshold) {
    int l = 1, r = INT_MIN, m;
    
    for (int i = 0; i < nums.size(); i++) {
      r = max(r, nums[i]);
    }
    
    while (l < r) {
      m = l + (r - l) / 2;
      if (isValid(nums, threshold, m)) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    
    return l;
  }
  
  bool isValid(vector<int>& nums, int threshold, int target) {
    int count = 0;
    for (int i = 0; i < nums.size(); i++) {
      count += (nums[i] - 1) / target + 1;
    }
    return count <= threshold; 
  }
};
