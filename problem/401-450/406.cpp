class Solution {
public:
  vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
    int size = people.size();
    vector<vector<int>> res;
    auto cmp = [](vector<int> a, vector<int> b) {
      return a[0] > b[0] || (a[0] == b[0] && a[1] < b[1]);
    };
    sort(people.begin(), people.end(), cmp);
    
    for (int i = 0; i < size; i++) {
      res.insert(res.begin() + people[i][1], people[i]);
    }
    
    return res;
  }
};
