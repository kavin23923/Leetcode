class Solution {
public:
  int removeDuplicates(vector<int>& nums) {
    int now = 0, n = nums.size();
    
    for (int i = 1; i < n; i++) {
      if (nums[i] != nums[now]) {
        nums[++now] = nums[i];
      } 
    }
      
    return n == 0 ? now : now + 1;
  }
};
