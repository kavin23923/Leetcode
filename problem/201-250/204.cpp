class Solution {
public:
  int countPrimes(int n) {
    int res = 0, now = 2;
    vector<bool> prime(n + 1, true);
    
    while (now < n) {
      res++;
      prime[now] = false;
      if (now < sqrt(n)) {
        for (int i = now * now; i < n; i += now) {
          prime[i] = false;
        }
      }
      while (now < n && !prime[now]) {
        now++;
      }
    }
    
    return res;
  }
};
