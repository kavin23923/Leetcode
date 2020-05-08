class Solution {
public:
  int numJewelsInStones(string J, string S) {
    int res = 0;
    unordered_set<char> jewel;
    
    for (char c : J) {
      jewel.insert(c);
    }
    for (char c : S) {
      if (jewel.find(c) != jewel.end()) {
        res++;
      }  
    }
    
    return res;
  }
};
