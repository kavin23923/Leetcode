class Solution {
public:
  int minSetSize(vector<int>& arr) {
    int size = 0;
    int set = 0;
    unordered_map<int, int> count;
    auto cmp = [](pair<int, int>& a, pair<int, int>& b) {
      return a.second < b.second;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> order(cmp);
    
    for (int tmp : arr) {
      count[tmp]++;
    }
    for (auto it = count.begin(); it != count.end(); it++) {
      order.push(make_pair(it->first, it->second));
    }
    while (size < arr.size() / 2) {
      size += order.top().second;
      order.pop();
      set++;
    }
    
    return set;
  }
};
