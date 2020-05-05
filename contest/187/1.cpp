class Solution {
public:
  string destCity(vector<vector<string>>& paths) {
    unordered_set<string> dist;
    for (auto &v : paths) {
      dist.insert(v[1]);
    }
    for (auto &v : paths) {
      dist.erase(v[0]);
    }
    return *(dist.begin());
  }
};
