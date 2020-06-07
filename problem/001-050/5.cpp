class Solution {
public:
  string longestPalindrome(string s) {
    string res = "";
    int len = s.size();
    int tmp;
    
    for (int i = 0; i < len; i++) {
      tmp = maxLen(s, i, i);
      if (tmp > res.size()) {
        res = s.substr(i - tmp / 2, tmp);
      }
      tmp = maxLen(s, i, i + 1);
      if (tmp > res.size()) {
        res = s.substr(i - tmp / 2 + 1, tmp);
      }
    }
    
    return res;
  }
  
  int maxLen(string &s, int l, int r) {
    int len = s.size();
    while (l >= 0 && r < len && s[l] == s[r]) {
      l--;
      r++;
    }
    return r - l - 1;
  }
};
