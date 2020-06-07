class Solution {
public:
  bool wordBreak(string s, vector<string>& wordDict) {
    int len = s.size();
    unordered_set<string> word(wordDict.begin(), wordDict.end());
    vector<bool> dp(len + 1, false);
    dp[0] = true;
    
    for (int i = 1; i <= len; i++) {
      for (int j = i; j > 0 ; j--) {
        if (word.find(s.substr(i - j, j)) != word.end() && dp[i - j]) {
          dp[i] = true;
          break;
        }
      }
    }
    
    return dp[len];
  }
};
