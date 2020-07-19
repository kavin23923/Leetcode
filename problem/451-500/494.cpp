class Solution {
public:
  int findTargetSumWays(vector<int>& nums, int S) {
    unordered_map<int, int> count;
    int n = nums.size();
    
    count[0] = 1;
    for (int i = 0; i < n; i++) {
      unordered_map<int, int> now;
      for (auto it = count.begin(); it != count.end(); it++) {
        now[it->first + nums[i]] += it->second;
        now[it->first - nums[i]] += it->second;
      }
      count = now;
    }
    
    return count[S];
  }
};
