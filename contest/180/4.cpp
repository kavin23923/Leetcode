class Solution {
public:
  int maxPerformance(int n, vector<int>& speed, vector<int>& efficiency, int k) {
    vector<pair<int, int>> worker;
    long long sum = 0, res = 0;
    priority_queue<int, vector<int>, greater<int>> choose;
    auto cmp = [](pair<int, int>& a, pair<int, int>& b) {return a.second > b.second;};
    int s, e;

    for (int i = 0; i < n; i++) {
      worker.push_back(make_pair(speed[i], efficiency[i]));
    }
    sort(worker.begin(), worker.end(), cmp);

    for (int i = 0; i < n; i++) {
      s = worker[i].first;
      e = worker[i].second;
      choose.push(s);
      sum += s;
      if (choose.size() > k) {
        sum -= choose.top();
        choose.pop();
      }
      res = max(res, sum * e);
    }
    
    return (int)(res % 1000000007);
  }
};

