class Solution {
public:
  int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
    int res = -1;
    int n = gas.size();
    int now = 0, g = 0, c = 0;
    
    for (int i = 0; i < n; i++) {
      now += gas[i] - cost[i];
      g += gas[i];
      c += cost[i];
      if (now >= 0 && res == -1) {
        res = i;
      } else if (now < 0){
        now = 0;
        res = -1;
      }
    }
    return g >= c ? res : -1;
  }
};
