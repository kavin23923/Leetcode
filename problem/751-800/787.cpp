class Solution {
public:
  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
    vector<int> cost(n, 1e9);
    int size = flights.size();
    
    cost[src] = 0;
    for (int i = 0; i <= K; i++) {
      vector<int> tmp = cost;
      for (int j = 0; j < size; j++) {
        tmp[flights[j][1]] = min(tmp[flights[j][1]], cost[flights[j][0]] + flights[j][2]);
      }
      cost = tmp;
    }
    
    return cost[dst] == 1e9 ? -1 : cost[dst];
  }
};
/**
 * Bellman-Ford algorithm
 */
