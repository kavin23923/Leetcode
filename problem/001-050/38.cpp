class Solution {
public:
  string countAndSay(int n) {
    string now = "1";
    
    for (int i = 1; i < n; i++) {
      string tmp = "";
      int count = 1;
      char pre = now[0];
      for (int j = 1; j < now.size(); j++) {
        if (now[j] != pre) {
          tmp += to_string(count) + pre;
          count = 1;
        } else {
          count++;
        }
        pre = now[j];
      }
      tmp += to_string(count) + pre;
      now = tmp;
    }
    return now;
  }
};
