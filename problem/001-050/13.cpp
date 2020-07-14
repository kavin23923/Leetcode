class Solution {
public:
  int romanToInt(string s) {
    int res = 0, len = s.size();
    unordered_map<char, int> num = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
    
    for (int i = 0; i < len; i++) {
      res += num[s[i]];
      if (i != len - 1 && num[s[i]] < num[s[i + 1]]) res -= num[s[i]] * 2;
    }
    
    return res;
  }
};
