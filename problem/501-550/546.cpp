class Solution {
public:
  int removeBoxes(vector<int>& boxes) {
    int n = boxes.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n)));
    return dfs(dp, boxes, 0, n - 1, 0); 
  }
  
  int dfs(vector<vector<vector<int>>> &dp, vector<int>& boxes, int start, int end, int same) {
    if (start > end) {
      return 0;
    } else if (dp[start][end][same]) {
      return dp[start][end][same];
    }
    
    dp[start][end][same] = (same + 1) * (same + 1) + dfs(dp, boxes, start + 1, end, 0);
    
    for (int i = start + 1; i <= end; i++) {
      if (boxes[start] == boxes[i]) {
        dp[start][end][same] = max(dp[start][end][same], dfs(dp, boxes, start + 1, i - 1, 0) + dfs(dp, boxes, i, end, same + 1));
      }
    }
      
    return dp[start][end][same];
  }
};
