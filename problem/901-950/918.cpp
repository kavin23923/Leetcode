class Solution {
public:
  int maxSubarraySumCircular(vector<int>& A) {
    int cur_max = 0, cur_min = 0, total_max = A[0], total_min = A[0], sum = 0;
    
    for (int a : A) {
      cur_max = max(cur_max + a, a);
      cur_min = min(cur_min + a, a);
      total_max = max(total_max, cur_max);
      total_min = min(total_min, cur_min);
      sum += a;
    }
    
    return total_max > 0 ? max(sum - total_min, total_max) : total_max;
  }
};

/**
 * Can use cur_max and cur_min to calculate the max or min to the current position.
 * The final result will be either the middle of the array or the end + the start of the array.
 * And the special case is all the numbers are negative. Then sum - total_min = 0, but we have to choose total_max.
 */
