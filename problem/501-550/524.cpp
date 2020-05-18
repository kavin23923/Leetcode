class Solution {
public:
  string findLongestWord(string s, vector<string>& d) {
    string res = "";
    
    auto cmp = [](string& a, string& b) {
      return a.size() > b.size() || (a.size() == b.size() && a < b);
    };
    sort(d.begin(), d.end(), cmp);
      
    for (string target : d) {
      if (judge(s, target)) {
        res= target;
        break;
      }
    }
    
    return res;
  }
  
  bool judge(string s, string target) {
    int len1 = s.size(), len2 = target.size();
    int now = 0;
    
    for (int i = 0; i < len1 && now < len2; i++) {
      if (s[i] == target[now]) {
        now++;
      }
    }
    
    return now == len2;
  }
};
