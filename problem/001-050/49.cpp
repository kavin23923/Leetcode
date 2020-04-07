class Solution {
public:
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> anagram;
    vector<vector<string>> res;
    string tmp;
    
    for (string& s : strs) {
      anagram[convert(s)].push_back(s);
    }
    
    for (auto it = anagram.begin(); it != anagram.end(); it++) {
      res.push_back(it->second);
    }
    
    return res;
  }
  
  string convert(string &s) {
    string res = "";
    int count[26] = {0};
    for (char c : s) {
      count[c - 'a']++;
    }
    for (int i = 0; i < 26; i++) {
      res += char('a' + i);
      res += to_string(count[i]);
    }
    return res;
  }
};
