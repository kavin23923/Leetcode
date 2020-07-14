class Solution {
public:
  bool isPalindrome(string s) {
    int l = 0, r = s.size() - 1;
    
    while (l < r) {
      while (l < r && !isalnum(s[l])) {
        l++;
      }
      while (l < r && !isalnum(s[r])) {
        r--;
      }
      if (isdigit(s[l]) || isdigit(s[r])) {
        if (s[l] != s[r]) return false;
      } else if (tolower(s[l]) != tolower(s[r])) {
        return false;
      }
      l++; r--;
    }
    
    return true;
  }
};
