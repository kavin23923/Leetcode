class Solution {
public:
  int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
    int m = nums1.size(), n = nums2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -5 * 1e8));
    int tmp;
    
    for (int i = 1; i <= m; i++) {
      for (int j = 1; j <= n; j++) {
        tmp = dp[i - 1][j - 1] < 0 ? 0 : dp[i - 1][j - 1];
        dp[i][j] = max(tmp + nums1[i - 1] * nums2[j - 1], max(dp[i][j - 1], dp[i - 1][j]));
      }
    }
    return dp[m][n];
  }
};
