class Solution {
public:
  vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
    vector<vector<int>> res;
    auto cmp = [](pair<int, int> a, pair<int, int> b) {
      return a.first < b.first;
    };
    priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> order(cmp);
    int dis;
    
    for (int i = 0; i < points.size(); i++) {
      dis = points[i][0] * points[i][0] + points[i][1] * points[i][1];
      order.push(make_pair(dis, i));
      if (order.size() > K) order.pop();
    }
    
    while(!order.empty()) {
      res.push_back(points[order.top().second]);
      order.pop();
    }
    
    return res;
  }
};
