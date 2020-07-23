class Solution {
public:
  vector<string> invalidTransactions(vector<string>& transactions) {
    vector<vector<string>> trans;
    vector<string> res;
    
    for (string &s : transactions) {
      trans.push_back(parse(s));
    }
    
    for (int i = 0; i < trans.size(); i++) {
      if (stoi(trans[i][2]) > 1000) {
        res.push_back(transactions[i]);
      } else {
        for (int j = 0; j < trans.size(); j++) {
          if (i == j) continue;
          if (trans[i][0] == trans[j][0] && trans[i][3] != trans[j][3] && abs(stoi(trans[i][1]) - stoi(trans[j][1])) <= 60) {
            res.push_back(transactions[i]);
            break;
          }
        }
      }
    }
    
    return res;
  }
  
  vector<string> parse(string target) {
    vector<string> res;
    string tmp = ""; 
    for (int i = 0; i <= target.size(); i++) {
      if (i == target.size() || target[i] == ',') {
        res.push_back(tmp);
        tmp = "";
      } else {
        tmp += target[i];
      }
    }
    return res;
  }
};
