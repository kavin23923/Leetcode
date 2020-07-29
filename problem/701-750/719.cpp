class Solution {
public:
  int smallestDistancePair(vector<int>& nums, int k) {
    int l = 0, r = 1000000, m;
    int pair;  
    
    sort(nums.begin(), nums.end());
    
    while (l < r) {
      m = l + (r - l) / 2;
      pair = numOfPair(nums, m);
      if (pair >= k) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    return l;
  }
  
  int numOfPair(vector<int>& nums, int target) {
    int pair = 0;
    int end = 0;
    int n = nums.size();
    
    for (int i = 0; i < n; i++) {
      while (end < n && nums[end] - nums[i] <= target) end++;
      pair += end - i - 1;
    }
    
    return pair;
  }
};
