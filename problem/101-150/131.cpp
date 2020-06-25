class Solution {
public:
  vector<vector<string>> partition(string s) {
    vector<vector<string>> res;
    vector<string> buf;
    dfs(res, buf, s, 0);
    return res;
  }
  
  void dfs(vector<vector<string>> &res, vector<string> &buf, string &s, int now) {
    if (now == s.size()) {
      if (buf.size() > 0) res.push_back(buf);
      return;
    }
    for (int i = now; i < s.size(); i++) {
      if (judge(s, now, i)) {
        buf.push_back(s.substr(now, i - now + 1));
        dfs(res, buf, s, i + 1);
        buf.pop_back();
      }
    }
  }
  
  bool judge(string &s, int l, int r) {
    while(l < r) {
      if (s[l++] != s[r--]) return false; 
    }
    return true;
  }
};
