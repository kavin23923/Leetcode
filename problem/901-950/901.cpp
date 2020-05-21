class StockSpanner {
public:
  StockSpanner() {
    
  }

  int next(int price) {
    int res = 1;
    while (!stock.empty() && stock.top().first <= price) {
      res += stock.top().second;
      stock.pop();
    }
    stock.push(make_pair(price, res));
    return res;
  }
  
private:
  stack<pair<int, int>> stock;
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

/**
 * Use a stack to store and skip some elements.
 * If the previous num is smaller or equal to  me, then the number larger than me will also be larger than these nums.
 * For each num, it will only be pushed and popped once.
 */
