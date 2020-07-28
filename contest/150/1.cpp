class Solution {
public:
  int countCharacters(vector<string>& words, string chars) {
    int res = 0;
    vector<int> count(26);
    
    for (char c : chars) {
      count[c - 'a']++;
    }
    
    for (string &w : words) {
      vector<int> tmp = count;
      bool good = true;
      for (char c : w) {
        if (--tmp[c - 'a'] < 0) {
          good = false;
          break;
        }
      }
      if (good) res += w.size();
    }
    
    return res;
  }
};
