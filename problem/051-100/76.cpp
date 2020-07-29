class Solution {
public:
  string minWindow(string s, string t) {
    unordered_map<char, int> count;
    int start = 0, end = 0, res = INT_MAX, head, target;
    int len = s.size();
    
    for (char c : t) count[c]++;
    
    target = count.size();
    while (end < len) {
      while (target > 0 && end < len) {
        if (--count[s[end++]] == 0) target--;
      }
      while (target == 0 && start < end) {
        if (end - start < res) {
          res = end - start;
          head = start;
        }
        if (++count[s[start++]] > 0) target++;
      }
    }
    
    return res == INT_MAX ? "" : s.substr(head, res);
  }
};
