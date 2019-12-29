class Solution {
public:
  bool isSolvable(vector<string>& words, string result) {
    unordered_set<char> letter;
    unordered_map<char, int> mapping;
    unordered_set<int> used;
    
    collectChar(words, result, letter);
    vector<char> vletter(letter.begin(), letter.end());
    return solve(words, result, vletter, mapping, 0, used);
  }
  
  void collectChar(vector<string>& words, string result, unordered_set<char>& letter) {
    for (int i = 0; i < words.size(); i++) {
      for (int j = 0; j < words[i].length(); j++) {
        letter.insert(words[i][j]); 
      }
    }
    for (int i = 0; i < result.size(); i++) {
      letter.insert(result[i]);
    }
  }
  
  bool solve(vector<string>& words, string result, vector<char>& vletter, unordered_map<char, int>& mapping, int now, unordered_set<int>& used) {
    if (now == vletter.size()) {
      return check(words, result, mapping); 
    } 
    
    for (int i = 0; i < 10; i++) {
      if (used.find(i) == used.end()) {
        used.insert(i);
        mapping[vletter[now]] = i;
        if (solve(words, result, vletter, mapping, now + 1, used)) {
          return true;
        }
        used.erase(i);
      }
    }
    
    return false;
  }
  
  bool check(vector<string>& words, string result, unordered_map<char, int>& mapping) {
    int res = 0;
    if (mapping[result[0]] == 0) return false;
    
    for (int i = 0; i < words.size(); i++) {
      int tmp = 0;
      if (mapping[words[i][0]] == 0) return false; 
      for (int j = words[i].length() - 1; j >= 0; j--) {
        tmp = tmp * 10 + mapping[words[i][j]];
      }
      res += tmp;
    }
    
    int num = 0;
    for (int i = result.length() - 1; i >= 0; i--) {
      num = num * 10 + mapping[result[i]];
    }
    
    return res == num;
  }
};