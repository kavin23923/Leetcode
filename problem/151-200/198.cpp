class Solution {
public:
  int rob(vector<int>& nums) {
    int pre = 0, prepre = 0, tmp;
    
    for (int n : nums) {
      int tmp = pre;
      pre = max(prepre + n, pre);
      prepre = tmp;
    }
    
    return max(pre, prepre);
  }
};
