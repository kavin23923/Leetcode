class Solution {
public:
  string lastSubstring(string s) {
    int len = s.size();
    int first = 0, second = 1, size = 0;
    
    while (second + size < len) {
      if (s[first + size] == s[second + size]) {
        size++;
      } else if (s[first + size] < s[second + size]) {
        first = second;
        second++;
        size = 0;
      } else {
        second = second + size + 1;
        size = 0;
      }
    }
    
    return s.substr(first);
  }
};
