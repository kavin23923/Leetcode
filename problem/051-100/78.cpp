class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> tmp;
    subset(nums, res, tmp, 0);
    return res;
  }
  
  void subset(vector<int>& nums, vector<vector<int>> &res, vector<int> &tmp, int now) {
    res.push_back(tmp);
    if (now == nums.size()) return;
    for (int i = now; i < nums.size(); i++) {
      tmp.push_back(nums[i]);
      subset(nums, res, tmp, i + 1);
      tmp.pop_back();
    }
  }
};
