class Solution {
public:
  vector<vector<int>> subsetsWithDup(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> tmp;
    sort(nums.begin(), nums.end());
    subset(nums, res, tmp, 0);
    return res;
  }

  void subset(vector<int> &nums, vector<vector<int>> &res, vector<int> &tmp, int now) {
    res.push_back(tmp);
    int i, size = nums.size();
    for (i = now; i < size; i++) {
      if (i == now || nums[i] != nums[i - 1]) {
        tmp.push_back(nums[i]);
        subset(nums, res, tmp, i + 1);
        tmp.pop_back();
      }
    }
  }
};
