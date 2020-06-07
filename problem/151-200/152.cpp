class Solution {
public:
  int maxProduct(vector<int>& nums) {
    int size = nums.size();
    int suffix = 1, prefix = 1;
    int res = INT_MIN;
    for (int i = 0; i < size; i++) {
      suffix = nums[size - 1 - i] * (suffix == 0 ? 1 : suffix);
      prefix = nums[i] * (prefix == 0 ? 1 : prefix);
      res = max(res, max(suffix, prefix));
    }
    return res;
  }
};
