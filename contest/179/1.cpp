class Solution {
public:
  string generateTheString(int n) {
    string res = "";
    bool flag = n % 2 == 0;
    for (int i = 0; i < n; i++) {
      res += 'a';
    }
    if (flag) res[res.length() - 1] = 'b';
    return res;
  }
};
