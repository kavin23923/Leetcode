class Solution {
public:
  vector<int> minSubsequence(vector<int>& nums) {
    int sum = 0, now = 0;
    vector<int> res;
    
    sort(nums.begin(), nums.end(), greater<int>());
    for (int n : nums) {
      sum += n;
    }
    
    for (int n : nums) {
      now += n;
      res.push_back(n);
      if (now * 2 > sum) {
        break;
      }
    }
    
    return res;
  }
};
