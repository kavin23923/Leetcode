class Solution {
public:
  int deleteAndEarn(vector<int>& nums) {
    int pre = 0, prepre = 0, tmp;
    int n = nums.size();
    vector<int> count(10001);
    
    for (int i = 0; i < n; i++) {
      count[nums[i]]++;
    }
    
    for (int i = 1; i <= 10000; i++) {
      tmp = pre;
      pre = max(pre, prepre + count[i] * i);
      prepre = tmp;
    }
    
    return max(pre, prepre);
  }
};
