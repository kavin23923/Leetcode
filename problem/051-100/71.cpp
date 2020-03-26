class Solution {
public:
  string simplifyPath(string path) {
    string res = "";
    string tmp = "";
    vector<string> sub;

    for (int i = 0; i <= path.size(); i++) {
      if (i != path.size() && path[i] != '/') {
        tmp += path[i];
      } else {
        if (tmp == "..") {
          if (sub.size() > 0) sub.pop_back();
        } else if (tmp != "." && tmp != "") {
          sub.push_back(tmp);
        }
        tmp = "";
      }
    }

    for (string s : sub) {
      res += "/" + s;
    }
    return res.size() == 0 ? "/" : res; 
  }
};
