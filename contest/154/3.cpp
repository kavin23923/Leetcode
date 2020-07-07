class Solution {
public:
  int kConcatenationMaxSum(vector<int>& arr, int k) {
    int res = 0, now = 0;
    int sum = 0;
    int n = arr.size(), size = k > 1 ? 2 * n : n;
    
    for (int i = 0; i < size; i++) {
      now = max(now + arr[i % n], 0) ;
      res = max(res, now);
      if (i < n) sum += arr[i];
    }
    
    if (sum > 0 && k - 2 > 0) {
      res = res + concateSum(sum, k - 2) % mod;
    }
    
    return res;
  }
  
  int concateSum(int sum, int k) {
    if (k == 1) {
      return sum;
    }
    int half = concateSum(sum, k / 2);
    return k & 1 ? sum + 2 * half % mod: 2 * half % mod;
  }
  
private:
  int mod = 1e9 + 7;
};
