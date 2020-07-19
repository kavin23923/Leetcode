class Solution {
public:
  int longestValidParentheses(string s) {
    int len = s.size();
    int res = 0;
    vector<int> dp(len);
    
    for (int i = 1; i < s.size(); i++) {
      if (s[i] == ')') {
        if (s[i - 1] == '(') {
          dp[i] = i - 2 >= 0 ? dp[i - 2] + 2 : 2;
        } else if (i - dp[i - 1] > 0 && s[i - dp[i - 1] - 1] == '('){
          dp[i] = dp[i - 1] + 2 + (i - dp[i - 1] > 1 ? dp[i - dp[i - 1] - 2] : 0);
        }
        res = max(res, dp[i]);
      }
    }
    
    return res;
  }
};
