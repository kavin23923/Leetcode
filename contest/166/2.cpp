class Solution {
public:
  vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
    vector<vector<int>> res;
    unordered_map<int, vector<int>> mapping;
    int size = groupSizes.size();
    
    for (int i = 0; i < size; i++) {
      mapping[groupSizes[i]].push_back(i);
      if (mapping[groupSizes[i]].size() == groupSizes[i]) {
        res.push_back(mapping[groupSizes[i]]);
        mapping[groupSizes[i]].clear();
      }
    }
    
    return res;
  }
};
