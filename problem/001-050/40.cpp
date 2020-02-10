class Solution {
public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> tmp;
    sort(candidates.begin(), candidates.end());
    search(candidates, target, res, tmp, 0);
    return res;
  }
  
  void search(vector<int>& candidates, int target, vector<vector<int>> &res, vector<int> &tmp, int now) {
    if (target == 0) {
      res.push_back(tmp);
      return;
    }
    
    int i, size = candidates.size();
    for (i = now; i < size && candidates[i] <= target; i++) {
      if (i != now && candidates[i] == candidates[i - 1]) continue;
      tmp.push_back(candidates[i]);
      search(candidates, target - candidates[i], res, tmp, i + 1);
      tmp.pop_back();
    }
  }
};
