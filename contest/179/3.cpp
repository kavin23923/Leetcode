class Solution {
public:
  int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
    int res = 0;
    queue<pair<int, int>> round;
    vector<vector<int>> sub(n);
    
    for (int i = 0; i < n; i++) {
      if (manager[i] != -1) {
        sub[manager[i]].push_back(i);
      }
    }
    
    round.push(make_pair(headID, 0));
    while (!round.empty()) {
      int id = round.front().first;
      int time = round.front().second;
      round.pop();
      for (int i = 0; i < sub[id].size(); i++) {
        int now = time + informTime[id];
        res = max(res, now);
        round.push(make_pair(sub[id][i], now));
      }
    }
    
    return res;
  }
};
