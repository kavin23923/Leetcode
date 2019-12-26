class Solution {
public:
  int findNumbers(vector<int>& nums) {
    int count = 0;
    int i;
    for (i = 0; i < nums.size(); i++) {
      count += judge(nums[i]);
    }
    return count;
  }
  
  int judge(int num) {
    int count = 0;
    while (num > 0) {
      count++;
      num /= 10;
    }
    return count % 2 == 0 ? 1 : 0;
  }
};