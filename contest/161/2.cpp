class Solution {
public:
  int numberOfSubarrays(vector<int>& nums, int k) {
    int size = nums.size();
    vector<int> count(size);
    for (int i = 0; i < size; i++) {
      if (i == 0 && nums[i] % 2 == 1) {
        count[i] = 1;
      } else if (i == 0) {
        count[i] = 0;
      } else {
        count[i] = count[i - 1] + (nums[i] % 2);
      }
    }
    int res = 0;
    for (int i = 0; i < size; i++) {
      for (int j = i; j < size; j++) {
        if (i == 0) {
          if (count[j] == k) {
            res++;
          }
        } else if (count[j] - count[i - 1] == k) {
          res++;
        }
      }
    }
    return res;
  }
};