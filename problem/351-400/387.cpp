class Solution {
public:
  int firstUniqChar(string s) {
    vector<int> place(26, -1); // -1 for not appear, -2 for twice, the other for place
    int len = s.length();
    int i;
    int res = INT_MAX;

    for (i = 0; i < len; i++) {
      if (place[s[i] - 'a'] == -1) {
        place[s[i] - 'a'] = i;
      } else {
        place[s[i] - 'a'] = -2;
      }
    }
    for (i = 0; i < 26; i++) {
      if (place[i] >= 0) {
        res = min(res, place[i]);
      }
    }
    return res == INT_MAX ? -1 : res;
  }
};
