class Solution {
public:
  bool isAnagram(string s, string t) {
    if (s.size() != t.size()) return false;
    vector<int> count1(26), count2(26);
    int len = s.size();
    
    for (int i = 0; i < len; i++) {
      count1[s[i] - 'a']++;
      count2[t[i] - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
      if (count1[i] != count2[i]) return false;
    }
    return true;
   }
};
