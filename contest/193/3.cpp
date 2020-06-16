class Solution {
public:
  int minDays(vector<int>& bloomDay, int m, int k) {
    int l = 1, r = 1e9, target;
    while (l < r) {
      target = l + (r - l) / 2;
      if (judge(bloomDay, m, k, target)) {
        r = target;
      } else {
        l = target + 1;
      }
    }
    return judge(bloomDay, m, k, r) ? r : -1;
  }
  
  bool judge(vector<int>& bloomDay, int m, int k, int target) {
    int now = 0;
    
    for (int i = 0; i <= bloomDay.size() && m > 0; i++) {
      if (i == bloomDay.size() || bloomDay[i] > target) {
        m -= now / k;
        now = 0;
      } else {
        now++;
      }
    }
    
    return m <= 0;
  }
};
