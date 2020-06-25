class Solution {
public:
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    permutation(nums, res, 0);
    return res;
  }
  
  void permutation(vector<int> &nums, vector<vector<int>> &res, int now) {
    if (now == nums.size()) {
      res.push_back(nums);
      return;
    }
    for (int i = now; i < nums.size(); i++) {
      swap(nums[now], nums[i]);
      permutation(nums, res, now + 1);
      swap(nums[now], nums[i]);
    }
  }
};
