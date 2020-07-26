class Solution {
public:
  int minFlips(string target) {
    int now = 0;
    int res = 0;
    
    for (char c : target) {
      if (c - '0' != now) {
        res++;
        now ^= 1;
      }
    }
    
    return res;
  }
};
