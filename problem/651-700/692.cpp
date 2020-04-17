class Solution {
public:
  vector<string> topKFrequent(vector<string>& words, int k) {
    vector<string> res;
    unordered_map<string, int> count;
    auto cmp = [](pair<string, int> a, pair<string, int> b) {
      return a.second > b.second || (a.second == b.second && a.first < b.first);
    };
    priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> order(cmp);
    
    for (string w : words) {
      count[w]++;
    }
    
    for (auto it : count) {
      order.push(make_pair(it.first, it.second));
      if (order.size() > k) {
        order.pop();
      }
    }
    while (!order.empty()) {
      res.push_back(order.top().first);
      order.pop();
    }
    reverse(res.begin(), res.end());
    
    return res;
  }
};
