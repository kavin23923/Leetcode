class Solution {
public:
  int findMaxLength(vector<int>& nums) {
    unordered_map<int, int> pos;
    int res = 0, now = 0, size = nums.size();
    
    pos[0] = -1;
    for (int i = 0; i < size; i++) {
      now += nums[i] > 0 ? 1 : -1;
      if (pos.find(now) != pos.end()) {
        res = max(res, i - pos[now]);
      } else {
        pos[now] = i;
      }
    }
    
    return res;
  }
};
/**
 * Use a hash map to map the zero-one count and position.
 * If there are two postions with the same count, then there is a subarray between these two positions.
 * };
 */
