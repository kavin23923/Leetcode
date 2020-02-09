class Solution {
public:
  int minSteps(string s, string t) {
    int count[26] = {0};
    for (auto c : s) {
      count[c - 'a']++;
    }
    for (auto c : t) {
      if (count[c - 'a'] > 0) {
        count[c - 'a']--;  
      }
    }
    int res = 0;
    for (int i = 0; i < 26; i++) {
      if (count[i] != 0) {
        res += count[i]; 
      }
    }
    return res;
  }
};
