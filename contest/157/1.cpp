class Solution {
public:
  int minCostToMoveChips(vector<int>& chips) {
    int res = INT_MAX;
    int n = chips.size();
    
    for (int i = 0; i < n; i++) {
      int round = 0;
      for (int j = 0; j < n; j++) {
        int diff = abs(chips[i] - chips[j]);
        if (diff & 1) {
          round++;
        }
      }
      res = min(round, res);
    }
    
    return res;
  }
};
