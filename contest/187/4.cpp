class Solution {
public:
  int kthSmallest(vector<vector<int>>& mat, int k) {
    int m = mat.size(), n = mat[0].size(), top;
    priority_queue<int, vector<int>> order;
    
    for (int i = 0; i < n && order.size() < k; i++) {
      order.push(mat[0][i]);
    }
    
    for (int i = 1; i < m; i++) {
      priority_queue<int, vector<int>> tmp;
      while (order.size() > 0) {
        top = order.top();
        order.pop();
        for (int j = 0; j < n; j++) {
          tmp.push(mat[i][j] + top);
          if (tmp.size() > k) {
            tmp.pop();
          }
        } 
      }
      order = tmp;
    }
    
    return order.top();
  }
};
