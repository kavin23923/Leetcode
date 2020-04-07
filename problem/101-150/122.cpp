class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int res = 0, diff;
    for (int i = 1; i < prices.size(); i++) {
      diff = prices[i] - prices[i - 1];
      if (diff > 0) {
        res += diff;
      }
    }
    return res;
  }
};
