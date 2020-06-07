class Solution {
public:
  int maxProfit(vector<int>& prices) {
    if (prices.size() == 0) return 0;
    // s1 for buy one, s2 for sell one, s3 for buy two, s4 for sell two
    int s1 = -prices[0], s2 = INT_MIN, s3 = INT_MIN, s4 = INT_MIN;
    for (int i = 0; i < prices.size(); i++) {
      s1 = max(s1, -prices[i]);
      s2 = max(s2, s1 + prices[i]);
      s3 = max(s3, s2 - prices[i]);
      s4 = max(s4, s3 + prices[i]);
    }
    return max(s4, 0);
  }
};
