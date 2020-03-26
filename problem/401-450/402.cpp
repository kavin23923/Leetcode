class Solution {
public:
  string removeKdigits(string num, int k) {
    string res = "";
    for (char c : num) { 
      while (res.size() > 0 && k > 0 && res[res.size() - 1] - '0' > c - '0') {
        res.pop_back();
        k--;
      }
      if (res.size() != 0 || c != '0') {
        res += c;
      }
    }
    while (k > 0 && res.size() > 0) {
      res.pop_back();
      k--;
    }
    return res.size() == 0 ? "0" : res;
  }
};
/**
 * The concept is using a stack. But we can just use a string as stack instead of creating a real stack.
 */
