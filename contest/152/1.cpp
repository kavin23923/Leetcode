class Solution {
public:
  int numPrimeArrangements(int n) {
    int mod = 1e9 + 7, prime, noprime;
    vector<long long> product(101, 1);
    
    for (int i = 2; i <= 100; i++) {
      product[i] = (product[i - 1] * i) % mod;
    }
    
    prime = numOfPrime(n);
    noprime = n - prime;
    
    return (int)(product[prime] * product[noprime] % mod);
  }
  
  int numOfPrime(int n) {
    int res = 0;
    vector<bool> prime(n + 1, true);
    
    for (int i = 2; i <= n; i++) {
      if (prime[i]) {
        res++;
        for (int j = i * i; j <= n; j += i) {
          prime[j] = false;
        }
      }
    }

    return res;
  }
};
