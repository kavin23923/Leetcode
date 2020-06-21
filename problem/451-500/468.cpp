class Solution {
public:
  string validIPAddress(string IP) {
    vector<string> ip;
    string buf = "";
    for (int i = 0; i <= IP.size(); i++) {
      if (i == IP.size() || IP[i] == ':' || IP[i] == '.') {
        ip.push_back(buf);
        buf = "";
      } else {
        buf += IP[i];
      }
    }
    if (ip.size() == 4 && isValidIPv4(ip)) {
      return "IPv4";
    } else if (ip.size() == 8 && isValidIPv6(ip)) {
      return "IPv6";
    } else {
      return"Neither";
    }
  }
  
  bool isValidIPv4(vector<string> &ip) {
    for (string &s : ip) {
      if (s.size() > 3 || s.size() == 0) return false;
      int tmp = 0;
      for (int i = 0; i < s.size(); i++) {
        if (s[i] < '0' || s[i] > '9') {
          return false;
        } else if (s[i] == '0' && i != s.size() - 1) {
          return false;
        }
        tmp = tmp * 10 + s[i] - '0';
      }
      if (tmp >= 256) return false;
    }
    return true;
  }
  
  bool isValidIPv6(vector<string> &ip) {
    for (string &s : ip) {
      if (s.size() > 4 || s.size() == 0) return false;
      for (int i = 0; i < s.size(); i++) {
        if (!(s[i] >= '0' && s[i] <= '9') && !(s[i] >= 'a' && s[i] <= 'z') && !(s[i] >= 'A' && s[i] <= 'Z')) {
          return false;
        } else if ((s[i] < '0' || s[i] > '9') && tolower(s[i]) > 'f') {
          return false;
        }
      }
    }
    return true;
  }
};
