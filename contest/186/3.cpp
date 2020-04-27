class Solution {
public:
  vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
    vector<int> res;
    int m = nums.size();
    vector<int> now(m, 0);
    set<int, greater<int>> exist;
    
    for (int i = 0; i < m; i++) {
      exist.insert(i);
    }
    
    for (int i = 0; i < m; i++) {
      auto it = exist.find(i);
      for (; it != exist.end(); it++) {
        res.push_back(nums[*it][now[*it]++]);
        if (now[*it] >= nums[*it].size()) {
          exist.erase(*it);
        }
      }
    }
    
    while (exist.size() != 0) {
      for (auto it = exist.begin(); it != exist.end(); it++) {
        res.push_back(nums[*it][now[*it]++]);
        if (now[*it] >= nums[*it].size()) {
          exist.erase(*it);
        }
      }
    }
    
    return res;
  }
};
