class Solution {
public:
  vector<vector<int>> generate(int numRows) {
    vector<vector<int>> res;
    if (numRows == 0) return res;
    res.push_back({1});  
    int i, j;

    for (i = 1; i < numRows; i++) {
      vector<int> tmp;
      vector<int> last = res.back();
      for (j = 0; j <= i; j++) {
        if (j == 0) {
          tmp.push_back(last[j]);
        } else if (j == i){
          tmp.push_back(last[j - 1]);
        } else {
          tmp.push_back(last[j] + last[j - 1]);
        }
      }
      res.push_back(tmp);
    }
    return res;
  }
};
