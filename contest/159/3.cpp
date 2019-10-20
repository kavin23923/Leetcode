class Solution {
public:
  int balancedString(string s) {
    unordered_map<char, int> count;
    for (int i = 0; i < s.length(); i++) {
      count[s[i]]++;
    }
    int start = diff(count, s.length() / 4);
    if (start == 0) return 0;
    start /= 2;
    int len = INT_MAX;
    for (int now = 0; now + start <= s.length(); now++) {
      unordered_map<char, int> tmp = count;
      int round = balance(tmp, now, start, s, len);
      len = min(len, round);
      if (len == start) {
        break;
      }
    }
    return len;
  }
  
  int diff(unordered_map<char, int> &count, int aver) {
    return abs(count['Q'] - aver) + abs(count['W'] - aver) + abs(count['E'] - aver) + abs(count['R'] - aver);
  }
  
  int balance(unordered_map<char, int> &count, int now, int start, string &s, int len) {
    bool flag = false;
    while (now + start <= s.length()) {
      unordered_map<char, int> tmp = count;
      for (int i = now; i < now + start ; i++) {
        tmp[s[i]]--;
      }
      if (diff(tmp, s.length() / 4) == start) {
        flag = true;
        break;
      }
      start++;
      if (start >= len) {
        break;
      }
    }
    return flag ? start : INT_MAX;
  }
};