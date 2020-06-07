class Solution {
public:
  bool canCross(vector<int>& stones) {
    int size = stones.size();
    if (size * (size - 1) / 2 < stones[size - 1]) return false;
    unordered_map<int, unordered_set<int>> jump;
    jump[0].insert(1);
    
    for (int i = 0; i < stones.size() - 1; i++) {
      for (auto it = jump[stones[i]].begin(); it != jump[stones[i]].end(); it++) {
        if (*it - 1 > 0) jump[stones[i] + *it].insert(*it - 1);
        jump[stones[i] + *it].insert(*it);
        jump[stones[i] + *it].insert(*it + 1);
      }
    }
    
    return jump[stones[size - 1]].size() > 0;
  }
};

