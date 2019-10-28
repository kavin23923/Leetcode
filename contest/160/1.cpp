class Solution {
public:
  vector<vector<int>> findSolution(CustomFunction& customfunction, int z) {
    vector<vector<int>> res;
    for (int i = 1; customfunction.f(i, 1) <= z; i++) {
      for (int j = 1; ;j++) {
        int tmp = customfunction.f(i, j);
        if (tmp == z) {
          res.push_back({i, j});
        } else if(tmp > z) {
          break;
        }
      }
    }
    return res;
  }
};