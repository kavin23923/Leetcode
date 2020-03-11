class Solution {
public:
  int maxEvents(vector<vector<int>>& events) {
    int d = 0, now = 0, res = 0;
    auto h_cmp = [](vector<int> &a, vector<int> &b) {
      return a[1] > b[1];
    };
    priority_queue<vector<int>, vector<vector<int>>, decltype(h_cmp)> candidate(h_cmp);
    auto v_cmp = [](vector<int> &a, vector<int> &b) {
      return a[0] < b[0];
    };
    sort(events.begin(), events.end(), v_cmp);
    
    while (now < events.size() || !candidate.empty()) {
      if (candidate.empty()) {
        d = events[now][0];
      }
      // add available events to target heap
      while (now < events.size() && events[now][0] <= d) {
        candidate.push(events[now++]);
      }
      // take the end first event
      candidate.pop();
      d += 1;
      res++;
      // remove unavailable events
      while (!candidate.empty() && candidate.top()[1] < d) {
        candidate.pop();
      }
    }
    return res;
  }
};
