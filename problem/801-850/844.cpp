class Solution {
public:
  bool backspaceCompare(string S, string T) {
    int len = S.size();
    int slen = 0, tlen = 0;
    
    for (char c : S) {
      if (c == '#') {
        if (slen > 0) {
          slen--;
        }
      } else {
        S[slen++] = c;
      }
    }
    
    for (char c : T) {
      if (c == '#') {
        if (tlen > 0) {
          tlen--;
        }
      } else {
        T[tlen++] = c;
      }
    }   
    
    return slen == tlen && S.substr(0, slen) == T.substr(0, tlen);
  }
};
