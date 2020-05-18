class Solution {
public:
  vector<int> peopleIndexes(vector<vector<string>>& favoriteCompanies) {
    vector<int> res;
    vector<pair<vector<string>, int>> favorite;
    vector<unordered_set<string>> exist;
    auto cmp = [](pair<vector<string>, int> &a, pair<vector<string>, int> &b) {
      return a.first.size() > b.first.size();
    };
    for (int i = 0; i < favoriteCompanies.size(); i++) {
      favorite.push_back(make_pair(favoriteCompanies[i], i));
    }
    sort(favorite.begin(), favorite.end(), cmp);
    
    for (int i = 0; i < favorite.size(); i++) {
      bool subset = false;
      for (int j = 0; j < exist.size() && !subset; j++) {
        bool found = true;
        for (string &s : favorite[i].first) {
          if (exist[j].find(s) == exist[j].end()) {
            found = false;
            break;
          }
        }
        if (found) subset = true;
      }
      if (!subset) res.push_back(favorite[i].second);
      unordered_set<string> tmp;
      for (string &s : favorite[i].first) {
        tmp.insert(s);
      }
      exist.push_back(tmp);
    }
    sort(res.begin(), res.end());
    return res;
  }
};
