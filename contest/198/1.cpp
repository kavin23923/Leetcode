class Solution {
public:
  int numWaterBottles(int numBottles, int numExchange) {
    int res = 0;
    int empty = 0;
    
    while (numBottles > 0) {
      res += numBottles;
      empty += numBottles;
      numBottles = empty / numExchange;
      empty %= numExchange;
    }
    
    return res;
  }
};
