class Solution {
public:
  vector<bool> canMakePaliQueries(string s, vector<vector<int>>& queries) {
    vector<bool> res;
    int n = s.size();
    vector<vector<int>> count;
    vector<int> tmp(26);

    count.push_back(tmp);    
    for (int i = 0; i < n; i++) {
      tmp[s[i] - 'a']++;
      count.push_back(tmp);
    }
    
    for (int i = 0; i < queries.size(); i++) {
      int odd = 0;
      for (int j = 0; j < 26; j++) {
        odd += (count[queries[i][1] + 1][j] - count[queries[i][0]][j]) & 1 ? 1 : 0;
      }
      res.push_back(odd / 2 > queries[i][2] ? false : true);
    }
    
    return res;
  }
};
