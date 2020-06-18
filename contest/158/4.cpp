class Solution {
public:
  int maxEqualFreq(vector<int>& nums) {
    vector<int> count(100001), freq(100001);
    int n = nums.size(), res = 0;
    int now, remain;
    
    for (int i = 1; i <= n; i++) {
      now = nums[i - 1];
      freq[count[now]]--;
      count[now]++;
      freq[count[now]]++;
      if (i == freq[count[now]] * count[now] && i != n) {
        res = max(res, i + 1);
      }
      remain = i - freq[count[now]] * count[now];
      if ((remain == count[now] + 1 && freq[remain] == 1) || remain == 1) {
        res = max(res, i);
      }
    }
    return res;
  }
};
