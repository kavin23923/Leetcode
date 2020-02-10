class Solution {
public:
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> tmp;
    sort(candidates.begin(), candidates.end());
    search(candidates, target, res, tmp, 0);
    return res;
  }
  
  void search(vector<int>& candidates, int target, vector<vector<int>>& res, vector<int>& tmp, int now)  {
    if (target == 0) {
      res.push_back(tmp);
    }
    
    for (int i = now; i < candidates.size() && candidates[i] <= target; i++) {
      tmp.push_back(candidates[i]);
      search(candidates, target - candidates[i], res, tmp, i);
      tmp.pop_back();
    }
  }
};
