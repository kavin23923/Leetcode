class Solution {
public:
  vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
    vector<vector<int>> res;
    int size1 = A.size(), size2 = B.size();
    int now1 = 0, now2 = 0;
    
    while (now1 < size1 && now2 < size2) {
      if (A[now1][1] < B[now2][0]) {
        now1++;
      } else if (B[now2][1] < A[now1][0]) {
        now2++;
      } else {
        vector<int> tmp(2);
        tmp[0] = max(A[now1][0], B[now2][0]);
        if (A[now1][1] < B[now2][1]) {
          tmp[1] = A[now1][1];
          now1++;
        } else {
          tmp[1] = B[now2][1];
          now2++;
        }
        res.push_back(tmp);
      }
    }
    
    return res;
  }
};
