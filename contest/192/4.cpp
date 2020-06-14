class Solution {
public:
  int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
    vector<vector<vector<int>>> paint(m + 1, vector<vector<int>>(target + 1, vector<int>(n + 1))); 
    int res = dfs(houses, cost, paint, 0, target, 0);
    return res > 1000000 ? -1 : res; // the cost may be larger than 1000001
  }

  int dfs(vector<int>& houses, vector<vector<int>>& cost, vector<vector<vector<int>>> &paint, int h, int target, int color) {
    if (h == houses.size() || target < 0) {
      return target == 0 && h == houses.size() ? 0 : 1000001;
    } else if (houses[h] != 0) {
      int not_same = houses[h] == color ? 0 : 1;
      return dfs(houses, cost, paint, h + 1, target - not_same, houses[h]);
    } else if (paint[h][target][color]) {
      return paint[h][target][color];
    }
    
    int res = INT_MAX;
    for (int i = 0; i < cost[h].size(); i++) {
      int not_same = i + 1 == color ? 0 : 1;
      res = min(res, dfs(houses, cost, paint, h + 1, target - not_same, i + 1) + cost[h][i]);
    }
    paint[h][target][color] = res;
    return res;
  }

};
