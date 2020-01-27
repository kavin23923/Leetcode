class Solution {
public:
  int removePalindromeSub(string s) {
    if (s.length() == 0) {
      return 0;
    }
    return isPalindrome(s) ? 1 : 2;
  }
  
  bool isPalindrome(string s) {
    int l = 0;
    int r = s.length() - 1;
    while (l < r) {
      if (s[l++] != s[r--]) {
        return false;
      }
    }
    return true;
  }
};
