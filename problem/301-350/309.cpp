class Solution {
public:
  int maxProfit(vector<int>& prices) {
    int size = prices.size();
    vector<int> nostock(size + 1);
    vector<int> hasstock(size + 1);
    vector<int> cooldown(size + 1);
    nostock[0] = 0;
    hasstock[0] = INT_MIN;
    cooldown[0] = INT_MIN;
    for (int i = 1; i <= size; i++) {
      nostock[i] = max(nostock[i - 1], cooldown[i - 1]);
      hasstock[i] = max(hasstock[i - 1], nostock[i - 1] - prices[i - 1]);
      cooldown[i] = hasstock[i - 1] + prices[i - 1];
    }
    return max(nostock[size], cooldown[size]);
  }
};
