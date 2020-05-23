class Solution {
public:
  int sumFourDivisors(vector<int>& nums) {
    int sum = 0;
    vector<int> tmp;
    
    for (int num : nums) {
      tmp = divisor(num);
      if (tmp.size() == 4) {
        sum += tmp[0] + tmp[1] + tmp[2] + tmp[3];
      }
    }
    return sum;
  }
  
  vector<int> divisor(int num) {
    vector<int> res;
    
    for (int i = 1; i * i <= num && res.size() <= 4; i++) {
      if (num % i == 0) {
        res.push_back(i);
        if (num / i != i) {
          res.push_back(num / i);
        }
      }
    }
    
    if (res.size() != 4) {
      res.clear();
    }
    return res;
  }
};
