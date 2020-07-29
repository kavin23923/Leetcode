class Solution {
public:
  int trap(vector<int>& height) {
    int res = 0;
    int l = 0, r = height.size() - 1;
    int max_l = 0, max_r = 0;
    
    while (l <= r) {
      if (height[l] <= height[r]) {
        if (height[l] > max_l) {
          max_l = height[l++];
        } else {
          res += max_l - height[l++];
        }
      } else {
        if (height[r] > max_r) {
          max_r = height[r--];
        } else {
          res += max_r - height[r--];
        }
      }
    }
    
    return res;
  }
};
