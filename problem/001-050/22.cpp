class Solution {
public:
  vector<string> generateParenthesis(int n) {
    vector<string> res;
    string tmp = "";
    int l = n, r = n;
    parentheses(res, tmp, l, r);
    return res;
  }
  
  void parentheses(vector<string> &res, string &tmp, int l, int r) {
    if (l == 0 && r == 0) {
      res.push_back(tmp);
      return;
    }
    if (l > 0) {
      tmp.push_back('(');
      parentheses(res, tmp, l - 1, r);
      tmp.pop_back();
    }
    if (r > l) {
      tmp.push_back(')');
      parentheses(res, tmp, l, r - 1);
      tmp.pop_back();
    }
  }
};
