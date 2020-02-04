class Solution {
public:
  int maxJumps(vector<int>& arr, int d) {
    int size = arr.size();
    int res = 0;
    int target;
    vector<int> dp(size, 0);
    vector<pair<int, int>> order;

    for (int i = 0; i < size; i++) {
      order.push_back(make_pair(arr[i], i));
    }
    sort(order.begin(), order.end());
    
    for (int i = 0; i < size; i++) {
      target = order[i].second;
      for (int j = 1; j <= d; j++) {
        if (target - j >= 0 && arr[target - j] < arr[target]) {
          dp[target] = max(dp[target], dp[target - j]);
        } else {
          break;
        }
      }
      for (int j = 1; j <= d; j++) {
        if (target + j < size && arr[target + j] < arr[target]) {
          dp[target] = max(dp[target], dp[target + j]);
        } else {
          break;
        }
      }
      dp[target] += 1;
    }

    for (int i = 0; i < size; i++) {
      res = max(res, dp[i]);
    }
    return res;
  }
};
