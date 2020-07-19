class Solution {
public:
  int lenLongestFibSubseq(vector<int>& A) {
    int n = A.size();
    int res = 0, sum;
    vector<vector<int>> dp(n, vector<int>(n));
    
    for (int i = 2; i < n; i++) {
      int l = 0, r = i - 1;
      while (l < r) {
        sum = A[l] + A[r];
        if (sum == A[i]) {
          dp[r][i] = dp[l][r] + 1;
          res = max(res, dp[r][i]);
          l++;
          r--;
        } else if (sum < A[i]) {
          l++;
        } else {
          r--;
        }
      }
    }
    
    return res == 0 ? res : res + 2;
  }
};
