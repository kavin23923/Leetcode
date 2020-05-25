class Solution {
public:
  int maxVowels(string s, int k) {
    int res = 0;
    int count = 0;
    int len = s.size();
    unordered_set<char> vowel = {'a', 'e', 'i', 'o', 'u'};
    
    for (int i = 0; i < k; i++) {
      if (vowel.find(s[i]) != vowel.end()) {
        count++;
      }
    }
    
    for (int i = 0; i <= len - k; i++) {
      if (i != 0) {
        if (vowel.find(s[i - 1]) != vowel.end()) {
          count--;
        }
        if (vowel.find(s[i - 1 + k]) != vowel.end()) {
          count++;
        }
      }
      res = max(res, count);
    }
    
    return res;
  }
};
