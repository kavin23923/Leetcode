class Solution {
public:
  int majorityElement(vector<int>& nums) {
    int count = 0, major;
    
    for (int n : nums) {
      if (count == 0) {
        major = n;
      }
      count += major == n ? 1 : -1;
    }
    return major;
  }
};
