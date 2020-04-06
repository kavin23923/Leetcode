class Solution {
public:
  int numSteps(string s) {
    int res = 0;
    int len;
    bool found;
    
    while (s.size() != 1) {
      if (s.back() == '0') {
        s.pop_back();
      } else {
        len = s.size();
        found = false;
        for (int i = len - 1; i >= 0 && !found; i--) {
          if (s[i] == '1') {
            s[i] = '0';
          } else {
            s[i] = '1';
            found = true;
          }
        }
        if (!found) {
          s = '1' + s;
        }
      }
      res++;
    }
    
    return res;
  }
};
