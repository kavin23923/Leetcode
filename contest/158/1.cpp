class Solution {
public:
  int balancedStringSplit(string s) {
    int now = 0, res = 0;
    for (char c : s) {
      now += c == 'L' ? 1 : -1;
      if (now == 0) res++;
    }
    return res;
  }
};
