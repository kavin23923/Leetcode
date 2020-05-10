class Solution {
public:
  vector<string> buildArray(vector<int>& target, int n) {
    vector<string> res;
    int now = 1, t = 0;
    while (t < target.size()) {
      if (target[t] != now) {
        res.push_back("Push");
        res.push_back("Pop");
      } else {
        res.push_back("Push");
        t++;
      }
      now++;
    }
    return res;
  }
};
