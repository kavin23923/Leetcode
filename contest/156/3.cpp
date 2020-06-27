class Solution {
public:
  string removeDuplicates(string s, int k) {
    string res = "";
    int len = s.size();
    vector<int> dup(len, 1);
    
    for (int i = 0; i < len; i++) {
      if (res.size() > 0 && s[i] == res.back() && dup[res.size() - 1] + 1 == k) {
        for (int j = 0; j < k - 1; j++) {
          dup[res.size() - 1] = 1;
          res.pop_back();
        }
      } else {
        if (res.size() > 0 && s[i] == res.back()) {
          dup[res.size()] = dup[res.size() - 1] + 1;
        }
        res += s[i];
      }
    }
    
    return res;
  }
};
