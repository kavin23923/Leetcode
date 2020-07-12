class Solution {
public:
  int numSub(string s) {
    int res = 0, mod = 1e9 + 7;
    int now = 0, len = s.size();
    long long tmp;
    
    for (int i = 0; i <= len; i++) {
      if (i == len || s[i] == '0') {
        tmp = (long long)now * (now + 1) / 2;
        res = (res + tmp) % mod;
        now = 0;
      } else {
        now++;
      }
    }
    
    return res;
  }
};
