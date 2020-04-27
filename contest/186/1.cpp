class Solution {
public:
  int maxScore(string s) {
    int len = s.size();
    int res = 0;
    vector<int> zero(len, 0);
    zero[0] = s[0] == '0' ? 1 : 0;
    
    for (int i = 1; i < len; i++) {
      zero[i] = zero[i - 1] + (s[i] == '0' ? 1 : 0);
    }
    
    for (int i = 0; i < len - 1; i++) {
      res = max(res, zero[i] + len - i - 1 - zero[len - 1] + zero[i]);
    }
    
    return res;
  }
};
