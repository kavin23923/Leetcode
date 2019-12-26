class Solution {
public:
  int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
    int res = 0;
    unordered_set<int> candidate;
    for (int i = 0; i < initialBoxes.size(); i++) {
      if (status[initialBoxes[i]] == 1) {
        addCandies(status, candies, keys, containedBoxes, initialBoxes[i], res, candidate);
      } else {
        candidate.insert(initialBoxes[i]);
      }
    }
    for (int i = 0; i < status.size(); i++) {
      if (status[i] == 1 && candidate.find(i) != candidate.end()) {
        addCandies(status, candies, keys, containedBoxes, i, res, candidate);
      }
    }
    
    return res;
  }
  
  void addCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, int target, int &res, unordered_set<int> &candidate) {
    res += candies[target];
    status[target] = -1;
    int i;
    for (i = 0; i < keys[target].size(); i++) {
      status[keys[target][i]] = 1;
    }
    for (i = 0; i < containedBoxes[target].size(); i++) {
      if (status[containedBoxes[target][i]] == 1) {
        addCandies(status, candies, keys, containedBoxes, containedBoxes[target][i], res, candidate);
      } else {
        candidate.insert(containedBoxes[target][i]);
      }
    }
  }
};