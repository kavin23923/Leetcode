class Solution {
public:
  int distanceBetweenBusStops(vector<int>& distance, int start, int destination) {
    int pos = 0, neg = 0;
    int now;
    int n = distance.size();
    
    now = start;
    while (now != destination) {
      pos += distance[now++];
      if (now == n) now = 0;
    }
    
    now = start;
    while (now != destination) {
      neg += distance[now - 1 >= 0 ? now - 1 : n - 1];
      now--;
      if (now == -1) now = n - 1;
    }
    
    return min(pos, neg);
  }
};
