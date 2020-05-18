class Solution {
public:
  int carFleet(int target, vector<int>& position, vector<int>& speed) {
    int res = 0, size = position.size();
    double last = -1;
    vector<pair<int, double>> order;
    auto cmp = [](pair<int,double> a, pair<int, double> b) {
      return a > b;
    };
    
    for (int i = 0; i < size; i++) {
      order.push_back(make_pair(position[i], ((double)target - position[i]) / speed[i]));
    }
    sort(order.begin(), order.end(), cmp);
    for (int i = 0; i < size; i++) {
      if (order[i].second > last) {
        res++;
        last = order[i].second;
      }
    }
    
    return res;
  }
};
