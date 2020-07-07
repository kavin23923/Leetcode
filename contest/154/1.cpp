class Solution {
public:
  int maxNumberOfBalloons(string text) {
    vector<int> count(26);
    int res = INT_MAX;
    
    for (char c : text) {
      count[c - 'a']++;
    }
    res = min(res, count['a' - 'a']);
    res = min(res, count['b' - 'a']);
    res = min(res, count['l' - 'a'] / 2);
    res = min(res, count['o' - 'a'] / 2);
    res = min(res, count['n' - 'a']);
    
    return res;
  }
};
