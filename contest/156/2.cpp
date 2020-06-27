class Solution {
public:
  int equalSubstring(string s, string t, int maxCost) {
    int res = 0, now = 0;
    int l = 0, r = 0, len = s.size();
    
    while (r < len) {
      now += abs(s[r] - t[r]);
      r++;
      while (now <= maxCost && r < len) {
        res = max(res, r - l);
        now += abs(s[r] - t[r]);
        r++;
      }
      while(l < r && now > maxCost) {
        now -= abs(s[l] - t[l]);
        l++;
      }
    }
    
    if (now <= maxCost) res = max(res, r - l);
    
    return res;
  }
};
