class Solution {
public:
  int maxSumDivThree(vector<int>& nums) {
    int sum = 0;
    vector<int> one;
    vector<int> two;
    for (int i = 0; i < nums.size(); i++) {
      sum += nums[i];
      if (nums[i] % 3 == 1) {
        one.push_back(nums[i]);
      } else if (nums[i] % 3 == 2) {
        two.push_back(nums[i]);
      }
    }
    sort(one.begin(), one.end());
    sort(two.begin(), two.end());
    
    if (sum % 3 == 1) {
      if (one.size() >= 1 && two.size() >= 2) {
        sum -= min(one[0], two[0] + two[1]);
      } else if (one.size() >= 1) {
        sum -= one[0];
      } else {
        sum -= two[0] + two[1];
      }
    } else if (sum % 3 == 2) {
      if (one.size() >= 2 && two.size() >= 1) {
        sum -= min(one[0] + one[1], two[0]);
      } else if (one.size() >= 2) {
        sum -= one[0] + one[1];
      } else {
        sum -= two[0];
      }
    }
    
    return sum;
  }
};
