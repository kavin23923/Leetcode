class Solution {
public:
  int jump(vector<int>& nums) {
    int n = nums.size();
    int res = 0, far = 0, end = 0;
    
    for (int i = 0; i < n - 1; i++) {
      far = max(far, i + nums[i]);
      if (end == i) {
        end = far;
        res++;
      }
    }
    
    return res;
  }
};
