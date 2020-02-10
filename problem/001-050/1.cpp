class Solution {
public:
  vector<int> twoSum(vector<int>& nums, int target) {
    vector<int> res;
    unordered_map<int, int> exist;
    int i, size = nums.size();
    for (i = 0; i < size; i++) {
      if (exist.find(nums[i]) != exist.end()) {
        res.push_back(exist[nums[i]]);
        res.push_back(i);
        break;
      }
      exist[target - nums[i]] = i;
    }
    return res;
  }
};
