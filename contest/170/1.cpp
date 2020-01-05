class Solution {
public:
  string freqAlphabets(string s) {
    string res = "";
    int now = 0;
    int size = s.length();
    while (now < size) {
      if (s[now] <= '2' && now + 2 < size && s[now + 2] == '#') {
        res += 'a' + (s[now] - '0') * 10 + s[now + 1] - '0' - 1;
        now += 3;
      } else {
        res += 'a' + s[now++] - '1';
      }
    }
    return res;
  }
};