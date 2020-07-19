class Solution {
public:
  int minDeletionSize(vector<string>& A) {
    int n = A.size(), len = A[0].size();
    int res = INT_MAX;
    vector<int> dp(len, 1); // lcs
    
    for (int i = 0; i < len; i++) {
      for (int j = 0; j < i; j++) {
        bool can = true;
        for (int k = 0; k < n; k++) {
          if (A[k][j] > A[k][i]) {
            can = false;
            break;
          }
        }
        if (can) {
          dp[i] = max(dp[i], dp[j] + 1);
        }
      }
      res = min(res, len - dp[i]);
    }
    
    return res;
  }
};
