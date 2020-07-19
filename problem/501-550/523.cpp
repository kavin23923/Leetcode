class Solution {
public:
  bool checkSubarraySum(vector<int>& nums, int k) {
    int n = nums.size();
    int sum = 0, target;
    unordered_map<int, int> pos;
    pos[0] = -1;
    
    for (int i = 0; i < n; i++) {
      sum += nums[i];
      target = k == 0 ? sum : sum % k; // corner case, k = 0
      if (pos.find(target) != pos.end()) {
        if (i - pos[target] >= 2) return true;
      } else {
        pos[target] = i;
      }
    }
    
    return false;
  }
};
