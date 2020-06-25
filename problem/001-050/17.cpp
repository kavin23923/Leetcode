class Solution {
public:
  vector<string> letterCombinations(string digits) {
    vector<string> res;
    unordered_map<char, vector<char>> mapping;
    string tmp = "";
    
    init(mapping);
    if (digits.size() > 0) {
      dfs(digits, mapping, res, tmp, 0);
    }
    return res;
  }
  
  void dfs(string &digits, unordered_map<char, vector<char>> &mapping, vector<string> &res, string &tmp, int now) {
    if (now == digits.size()) {
      res.push_back(tmp);
      return;
    }
    for (int i = 0; i < mapping[digits[now]].size(); i++) {
      tmp.push_back(mapping[digits[now]][i]);
      dfs(digits, mapping, res, tmp, now + 1);
      tmp.pop_back();
    }
  }
  
  void init(unordered_map<char, vector<char>> &mapping) {
    mapping['2'] = {'a', 'b', 'c'};
    mapping['3'] = {'d', 'e', 'f'};
    mapping['4'] = {'g', 'h', 'i'};
    mapping['5'] = {'j', 'k', 'l'};
    mapping['6'] = {'m', 'n', 'o'};
    mapping['7'] = {'p', 'q', 'r', 's'};
    mapping['8'] = {'t', 'u', 'v'};
    mapping['9'] = {'w', 'x', 'y', 'z'};
  }
};
