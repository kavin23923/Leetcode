class Solution {
public:
  string rankTeams(vector<string>& votes) {
    int size = votes[0].size();
    unordered_map<char, vector<int>> count;
    vector<pair<char, vector<int>>> team;
    string res = "";
    auto cmp = [size](pair<char, vector<int>>& a,  pair<char, vector<int>>& b) {
      for (int i = 0; i < size; i++) {
        if (a.second[i] != b.second[i]) {
          return a.second[i] > b.second[i];
        }
      }
      return a.first < b.first;
    };
    
    
    for (string s : votes) {
      for (int i = 0; i < size; i++) {
        if (count.find(s[i]) == count.end()) {
          count[s[i]] = vector<int>(size);
        }
        count[s[i]][i]++;
      }
    }
    
    for (auto it = count.begin(); it != count.end(); it++) {
      team.push_back(make_pair(it->first, it->second));
    }    
    sort(team.begin(), team.end(), cmp);
    
    for (auto p : team) {
      res += p.first;
    }
    
    return res;
  }
};
