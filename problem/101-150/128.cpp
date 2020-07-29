class Solution {
public:
  int longestConsecutive(vector<int>& nums) {
    int n = nums.size(), res = 0, start;
    unordered_set<int> num;
    
    for (int i = 0; i < n; i++) {
      num.insert(nums[i]);
    }
    
    for (int i = 0; i < n; i++) {
      if (num.find(nums[i] - 1) == num.end()) {
        start = nums[i];
        while (num.find(start) != num.end()) {
          start++;
        }
        res = max(res, start - nums[i]);
      }
    }
    
    return res;
  }
};
