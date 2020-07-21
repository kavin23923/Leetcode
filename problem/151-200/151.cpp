class Solution {
public:
  string reverseWords(string s) {
    string res = "";
    string tmp = "";
    int len = s.size();
    
    for (int i = 0; i <= len; i++) {
      if (i == len || s[i] == ' ') {
        if (tmp.size() > 0) {
          res = tmp + " " + res;
          tmp = "";
        }
      } else {
        tmp += s[i];
      }
    }
    
    if (res.size() > 0) res.pop_back();
    return res;
  }
};
