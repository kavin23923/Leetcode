class Solution {
public:
  int findKthLargest(vector<int>& nums, int k) {
    int l = 0, r = nums.size() - 1;
    int res;
    while (true) {
      int pos = partition(nums, l, r);
      if (pos == k - 1) {
        res = nums[pos];
        break;
      } else if (pos > k - 1) {
        r = pos - 1;
      } else {
        l = pos + 1;
      }
    }
    return res;
  }
  
  int partition(vector<int>& nums, int l, int r) {
    int start = l, pivot = nums[l++];
    while (l <= r) {
      if (nums[l] >= pivot) {
        l++;
      } else if (nums[r] <= pivot) {
        r--;
      } else {
        swap(nums[l++], nums[r--]);
      }
    }
    swap(nums[start], nums[r]);
    return r;
  }
};
