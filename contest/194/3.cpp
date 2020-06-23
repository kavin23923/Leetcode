class Solution {
public:
  vector<int> avoidFlood(vector<int>& rains) {
    vector<int> res;
    unordered_map<int, int> lake;
    set<int> dry;
    int size = rains.size();
    
    for (int i = 0; i < size; i++) {
      if (rains[i]) {
        if (lake.find(rains[i]) != lake.end()) {
          auto it = dry.upper_bound(lake[rains[i]]);
          if (it == dry.end()) return vector<int>();
          res[*it] = rains[i];
          dry.erase(it);
        }
        res.push_back(-1);
        lake[rains[i]] = i;
      } else {
        dry.insert(i);
        res.push_back(1);
      }
    }
    
    return res;
  }
};
