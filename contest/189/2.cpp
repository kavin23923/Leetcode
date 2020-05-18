class Solution {
public:
  string arrangeWords(string text) {
    vector<pair<string, int>> data;
    int now = 0;
    string tmp = "";
    
    text[0] = tolower(text[0]);
    for (int i = 0; i <= text.size(); i++) {
      if (i == text.size() || text[i] == ' ') {
        data.push_back(make_pair(tmp, now++));
        tmp = "";
      } else {
        tmp += text[i];
      }
    }
    auto cmp = [](pair<string, int> a, pair<string, int> b) {
      return a.first.size() < b.first.size() || (a.first.size() == b.first.size() && a.second < b.second);
    };
    sort(data.begin(), data.end(), cmp);
    
    string res = data[0].first;
    res[0] = toupper(res[0]);
    for (int i = 1; i < data.size(); i++) {
      res += " " + data[i].first;
    }
    return res;
  }
};
