class Solution {
public:
  int nthUglyNumber(int n) {
    vector<int> dp(n);
    int two = 0, three = 0, five = 0;
    int tmp1, tmp2, tmp3;
    dp[0] = 1;
    
    for (int i = 1; i < n; i++) {
      tmp1 = dp[two] * 2;
      tmp2 = dp[three] * 3;
      tmp3 = dp[five] * 5;
      dp[i] = min(min(tmp1, tmp2), tmp3);
      if (tmp1 == dp[i]) {
        two++;
      }
      if (tmp2 == dp[i]) {
        three++;
      }
      if (tmp3 == dp[i]) {
        five++;
      }
    }
    return dp[n - 1];
  }
};
/**
 * Can also solve by heap:
 * class Solution {
 * public:
 *   int nthUglyNumber(int n) {
 *     int now = 0;
 *     long long res;
 *     priority_queue<long long, vector<long long>, greater<long long>> ugly;
 *     ugly.push(1);
 *
 *     while (now++ < n) {
 *       res = ugly.top();
 *       while (!ugly.empty() && ugly.top() == res) {
 *         ugly.pop();
 *       }
 *       ugly.push(res * 2);
 *       ugly.push(res * 3);
 *       ugly.push(res * 5);
 *     }
 *     return (int)res;
 *   }
 * };
 */
