class Solution {
public:
  bool checkValidString(string s) {
    int lmin = 0, lmax = 0;
    
    for (char c : s) {
      if (c == '(') {
        lmin++;
        lmax++;
      } else if (c == ')') {
        lmin = max(lmin - 1, 0);
        lmax--;
      } else {
        lmin = max(lmin - 1, 0);
        lmax++;
      }
      if (lmax < 0) {
        return false;
      }
    }
    
    return lmin == 0;
  }
};
/**
 * Should set lmin to 0 if lmin < 0. 
 * It means we try to replace * with ), and it causes the number of ) too much, so we should not do it.
 */ 
