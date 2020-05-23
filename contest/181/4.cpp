class Solution {
public:
  string longestPrefix(string s) {
    int res = 0;
    int len = s.size();
    long long prefix = 0, suffix = 0, mod = 1e9 + 7, base = 1;
    int c1, c2;
    
    for (int i = 0; i < len - 1; i++) {
      c1 = s[i] - 'a';
      c2 = s[len - 1 - i] - 'a';
      prefix = (prefix * 26 + c1) % mod;
      suffix = (suffix + base * c2) % mod;
      base = (base * 26) % mod;
      if (prefix == suffix) res = i + 1;
    }
    return s.substr(0, res);
  }
};
