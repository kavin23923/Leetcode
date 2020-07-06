class Solution {
public:
  int getLastMoment(int n, vector<int>& left, vector<int>& right) {
    int res = 0;
    
    for (int ant : left) {
      res = max(res, ant - 0);
    }
    for (int ant : right) {
      res = max(res, n - ant);
    }
    
    return res;
  }
};
