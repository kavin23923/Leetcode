class Solution {
public:
  vector<string> findRepeatedDnaSequences(string s) {
    unordered_map<char, int> mapping;
    vector<string> res;
    unordered_map<int, int> exist;
    int len = s.size(), now = 0, mask = (1 << 20) - 1;
    
    if (len < 10) return res;
    init(mapping);
    for (int i = 0; i < 10; i++) {
      now = (now << 2) | mapping[s[i]];
    }
    exist[now]++;
    
    for (int i = 10; i < len; i++) {
      now = ((now << 2) & mask) | mapping[s[i]];
      if (++exist[now] == 2) {
        res.push_back(s.substr(i - 9, 10));
      }
    }
    
    return res;
  }
  
  void init(unordered_map<char, int> &mapping) {
    mapping['A'] = 0;
    mapping['C'] = 1;
    mapping['G'] = 2;
    mapping['T'] = 3;
  }
};
