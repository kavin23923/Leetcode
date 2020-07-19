class Solution {
public:
  vector<string> maxNumOfSubstrings(string s) {
    int len = s.size();
    vector<string> res;
    vector<int> l(26, INT_MAX), r(26, INT_MIN);
    
    for (int i = 0; i < len; i++) {
      l[s[i] - 'a'] = min(l[s[i] - 'a'], i);
      r[s[i] - 'a'] = max(r[s[i] - 'a'], i);
    }
    
    int right = -1;
    for (int i = 0; i < len; i++) {
      if (i == l[s[i] - 'a']) {
        int new_right = updateRight(l, r, i, s);
        if (new_right != -1) {
          if (new_right > right) {
            res.push_back("");
          }
          right = new_right;
          res.back() = s.substr(i, right - i + 1);
        } 
      }
    }
    
    return res;
  }
  
  int updateRight(vector<int> &l, vector<int> &r, int now, string &s) {
    int right = r[s[now] - 'a'];
    for (int i = now; i <= right; i++) {
      if (l[s[i] - 'a'] < now) return -1;
      right = max(right, r[s[i] - 'a']);
    }
    return right;
  }
};
