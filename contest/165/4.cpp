class Solution {
public:
  int palindromePartition(string s, int k) {
    int len = s.size();
    vector<vector<int>> cost(len, vector<int>(len, 0));
    vector<vector<int>> dp(len + 1, vector<int>(k + 1, 1e9));
    for (int start = 0; start < len; start++) {
      for (int end = start; end < len; end++) {
        cost[start][end] = palindrome(s, start, end);
      }
    }
    
    dp[0][0] = 0;
    for (int i = 1; i <= len; i++) {
      for (int j = 1; j <= min(k, i); j++) {
        for (int a = 0; a <= i - 1; a++) {
          dp[i][j] = min(dp[i][j], dp[a][j - 1] + cost[a][i - 1]);
        }
      }
    }
    
    return dp[len][k];
  }
  
  int palindrome(string &s, int start, int end) {
    int cost = 0;
    while (start < end) {
      if (s[start++] != s[end--]) {
        cost++;
      }
    }
    return cost;
  }
};
