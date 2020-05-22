class Solution {
public:
  int kthSmallest(vector<vector<int>>& matrix, int k) {
    int n = matrix.size();
    int l = matrix[0][0], r = matrix[n - 1][n - 1], m;
    int count, j;
    
    // O(log(max - min))
    while (l < r) {
      m = l + (r - l) / 2;
      count = 0;
      j = n - 1;
      // O(n)
      for (int i = 0; i < n; i++) {
         while (j >= 0 && matrix[i][j] > m) {
           j--;
         }
        count += j + 1;
      }
      if (count >= k) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    return l;
  }
};
