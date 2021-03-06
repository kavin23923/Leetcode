class Solution {
public:
  vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
    vector<int> res;
    int size = nums.size(), count;
    
    for (int i = 0; i < size; i++) {
      count = 0;
      for (int j = 0; j < size; j++) {
        if (i != j && nums[j] < nums[i]) {
          count++;
        }
      }
      res.push_back(count);
    }
    return res;
  }
};
