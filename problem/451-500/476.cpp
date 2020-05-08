class Solution {
public:
  int findComplement(int num) {
    int base = 1;
    int res = 0;
    
    while (num > 0) {
      if (!(num & 1)) {
        res |= base;
      }
      base <<= 1;
      num >>= 1;
    }
    
    return res;
  }
};
