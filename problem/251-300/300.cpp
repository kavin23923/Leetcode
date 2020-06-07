class Solution {
public:
  int lengthOfLIS(vector<int>& nums) {
    int size = nums.size();
    int res = 0, pos;
    vector<int> dp(size);
   
    for (int i = 0; i < size; i++) {
      pos = binarySearch(dp, 0, res, nums[i]);
      dp[pos] = nums[i];
      if (pos == res) {
        res++;
      }
    }
    
    return res;
  }
  
  int binarySearch(vector<int> &dp, int start, int end, int target) {
    int mid;
    while (start < end) {
      mid = start + (end - start) / 2;
      if (target <= dp[mid]) {
        end = mid;
      } else {
        start = mid + 1;
      }
    }
    return start;
  }
};

/**
 * The original dp is O(n^2). This approach is using dp + binary search.
 */
