class Solution {
public:
  int lengthOfLongestSubstring(string s) {
    int res = 0;
    int l = -1;
    int len = s.size();
    unordered_map<char, int> pos;
    
    for (int i = 0; i < len; i++) {
      if (pos.find(s[i]) != pos.end()) {
        l = max(l, pos[s[i]]);
      }
      res = max(res, i - l);
      pos[s[i]] = i;
    }
    
    return res;
  }
};
