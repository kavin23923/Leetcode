class Solution {
public:
  void sortColors(vector<int>& nums) {
    int size = nums.size();
    int zero = 0, two = size - 1;
    int i;
    
    while (i <= two) {
      if (nums[i] == 0) {
        swap(nums[i++], nums[zero++]);
      } else if (nums[i] == 2) {
        swap(nums[i], nums[two--]);
      } else {
        i++;
      }
    }
  }
};
