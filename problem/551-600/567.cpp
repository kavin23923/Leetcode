class Solution {
public:
  bool checkInclusion(string s1, string s2) {
    vector<int> count(26);
    vector<int> target(26);
    
    if (s1.size() > s2.size()) return false;
    
    for (char c : s1) {
      count[c - 'a']++;
    }
    for (int i = 0; i < s1.size(); i++) {
      target[s2[i] - 'a']++;
    }
    for (int i = 0; i <= s2.size() - s1.size(); i++) {
      if (i != 0) {
        target[s2[i - 1] - 'a']--;
        target[s2[s1.size() + i - 1] - 'a']++;
      }
      if (same(count, target)) {
        return true;
      }
    }
    
    return false;
  }
  
  bool same(vector<int> &count, vector<int> &target) {
    for (int i = 0; i < 26; i++) {
      if (count[i] != target[i]) {
        return false;
      }
    }
    return true;
  }
};
