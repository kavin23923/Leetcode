class Solution {
public:
  vector<string> printVertically(string s) {
    vector<string> res;
    vector<string> subs = parse(s);
    vector<int> now(subs.size(), 0);
    
    while (true) {
      int space = 0;
      string tmp = "";
      bool flag = false;
      for (int i = 0; i < subs.size(); i++) {
        if (now[i] < subs[i].size()) {
          for (int j = 0; j < space; j++) {
            tmp += ' ';
          }
          tmp += subs[i][now[i]++];
          flag = true;
          space = 0;
        } else {
          space++;
        }
      }
      if (!flag) {
        break;
      }
      res.push_back(tmp);
    }
    
    return res;
  }
  
  vector<string> parse(string s) {
    int len = s.size();
    vector<string> subs;
    string tmp = ""; 
    
    for (int i = 0; i <= len; i++) {
      if (i == len || s[i] == ' ') {
        subs.push_back(tmp);
        tmp = "";
      } else {
        tmp += s[i];
      }
    }
    
    return subs;
  }
};
