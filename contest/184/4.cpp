class Solution {
public:
  int numOfWays(int n) {
    long long three = 6, two = 6;
    long long tmp_three, tmp_two;
    int mod = 1000000007;
    
    for (int i = 1; i < n; i++) {
      tmp_three = three * 2 + two * 2;
      tmp_two = three * 2 + two * 3;
      three = tmp_three % mod;
      two = tmp_two % mod;
    }
    
    return (three + two) % mod;
  }
};
