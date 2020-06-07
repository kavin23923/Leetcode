class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int res = 0;
    int lowest = INT_MAX;
    
    for (int price : prices) {
      res = max(res, price - lowest);
      lowest = min(lowest, price);
    }
    return res;
  }
};
