class Solution {
public:
  vector<int> topKFrequent(vector<int>& nums, int k) {
    vector<int> res;
    unordered_map<int, int> count;
    auto cmp = [](pair<int, int> a, pair<int, int> b) {
      return a.second > b.second;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> order(cmp);
    
    for (int n : nums) {
      count[n]++;
    }
    
    for (auto it = count.begin(); it != count.end(); it++) {
      order.push(make_pair(it->first, it->second));
      if (order.size() > k) {
        order.pop();
      }
    }
    
    while(!order.empty()) {
      res.push_back(order.top().first);
      order.pop();
    }
    
    return res;
  }
};
