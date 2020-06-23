class Solution {
public:
  vector<string> getFolderNames(vector<string>& names) {
    vector<string> res;
    unordered_map<string, int> num;
    int target;
    
    for (string &s : names) {
      if (num.find(s) != num.end()) {
        target = num[s];
        while (num.find(s + '(' + to_string(target) + ')') != num.end()) {
          target++;
        }
        string tmp = s + '(' + to_string(target) + ')';
        num[tmp] = 1;
        res.push_back(tmp);
        num[s] = target + 1;
      } else {
        res.push_back(s);
        num[s] = 1;
      }
    }
    
    return res;
  }
};
