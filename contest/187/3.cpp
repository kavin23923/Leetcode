class Solution {
public:
  int longestSubarray(vector<int>& nums, int limit) {
    int res = 1, l = 0, r = 0;
    map<int, int> order;
    int size = nums.size();
    
    order[nums[r]] = 1;
    
    while (r < size) {
      while (r < size && order.rbegin()->first - order.begin()->first <= limit) {
        res = max(res, r - l + 1);
        r++;
        if (r < size) {
          order[nums[r]]++;
        }
      }
      while (l < r && order.rbegin()->first - order.begin()->first > limit) {
        if (--order[nums[l]] == 0) {
          order.erase(nums[l]);
        }
        l++;
      }
    }
    
    return res;
  }
};
