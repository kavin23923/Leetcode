class Solution {
public:
  vector<int> filterRestaurants(vector<vector<int>>& restaurants, int veganFriendly, int maxPrice, int maxDistance) {
    int i;
    auto cmp = [](vector<int> &a, vector<int> &b) {
      if (a[1] == b[1]) {
        return a[0] < b[0];
      } else {
        return a[1] < b[1];
      }
    };
    priority_queue<vector<int>, vector<vector<int>>, decltype(cmp)> order(cmp);
    
    for (i = 0; i < restaurants.size(); i++) {
      if (restaurants[i][3] <= maxPrice && restaurants[i][4] <= maxDistance && (!veganFriendly || restaurants[i][2])) {
        order.push(restaurants[i]);
      }
    }
    
    vector<int> res;
    vector<int> tmp;
    while (!order.empty()) {
      tmp = order.top();
      order.pop();
      res.push_back(tmp[0]);
    }
    return res;
  }
};
