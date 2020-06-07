class Solution {
public:
  int splitArray(vector<int>& nums, int m) {
    long long l = 1, r = 0, mid;
    
    for (int i = 0; i < nums.size(); i++) {
      r += nums[i];
    }
    if (m == 1) return (int)r;

    while (l < r) {
      mid = l + (r - l) / 2;
      if (isValid(nums, m, mid)) {
        r = mid;
      } else {
        l = mid + 1;
      }
    }
    
    return (int)l;
  }
  
  bool isValid(vector<int>& nums, int m, long long target) {
    long long now = 0;
    int count = 1;
    for (int i = 0; i < nums.size() && count <= m; i++) {
      if (nums[i] > target) return false;
      if (now + nums[i] > target) {
        count++;
        now = 0;
      }
      now += nums[i];
    }
    return count <= m;
  }
};
