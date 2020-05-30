class Solution {
public:
  vector<int> getNoZeroIntegers(int n) {
    vector<int> res(2);
    
    for (int i = 1; i < n; i++) {
      if (isValid(i) && isValid(n - i)) {
        res[0] = i;
        res[1] = n - i;
        break;
      } 
    }
    
    return res;
  }
  
  bool isValid(int num) {
    while (num > 0) {
      if (num % 10 == 0) {
        return false;
      }
      num /= 10;
    }
    return true;
  }
};
