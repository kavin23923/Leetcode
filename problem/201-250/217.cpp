class Solution {
public:
  bool containsDuplicate(vector<int>& nums) {
    unordered_set<int> exist;
    int n = nums.size();
    
    for (int i = 0; i < n; i++) {
      if (exist.find(nums[i]) != exist.end()) {
        return true;
      }
      exist.insert(nums[i]);
    }
    return false;
  }
};
