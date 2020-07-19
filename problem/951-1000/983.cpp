class Solution {
public:
  int mincostTickets(vector<int>& days, vector<int>& costs) {
    int n = days.size();
    int d = days[n - 1];
    int tmp;
    vector<int> cost(d + 1);
    unordered_set<int> travel;
    
    for (int i = 0; i < n; i++) {
      travel.insert(days[i]);
    }
    
    for (int i = 1; i <= d; i++) {
      if (travel.find(i) == travel.end()) {
        cost[i] = cost[i - 1];
      } else {
        tmp = cost[i - 1] + costs[0];
        tmp = min(tmp, cost[max(0, i - 7)] + costs[1]);
        tmp = min(tmp, cost[max(0, i - 30)] + costs[2]);
        cost[i] = tmp;
      }
    }
    
    return cost[d];
  }
};
