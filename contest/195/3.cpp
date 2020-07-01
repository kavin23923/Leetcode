class Solution {
public:
  int numSubseq(vector<int>& nums, int target) {
    int res = 0, mod = 1e9 + 7;
    int n = nums.size();
    int l = 0, r = n - 1;
    vector<int> pow(n, 1);
    
    for (int i = 1; i < n; i++) {
      pow[i] = pow[i - 1] * 2 % mod;
    }
    
    sort(nums.begin(), nums.end());
    while (l <= r) {
      if (nums[l] + nums[r] <= target) {
        res = (res + pow[r - l]) % mod;
        l++;
      } else {
        r--;
      }
    }
    
    return res;
  }
};
