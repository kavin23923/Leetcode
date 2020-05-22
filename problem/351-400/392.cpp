class Solution {
public:
  bool isSubsequence(string s, string t) {
    int len1 = s.size(), len2 = t.size();
    int now = 0;
    
    for (int i = 0; i < len2; i++) {
      if (now < len1 && s[now] == t[i]) {
        now++;
      }
    }
    return now == len1;
  }
};
