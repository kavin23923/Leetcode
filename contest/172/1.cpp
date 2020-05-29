class Solution {
public:
  int maximum69Number (int num) {
    vector<int> d = digit(num);
    int res = 0, flag = 0;
    for (int n : d) {
      if (n == 6 && flag == 0) {
        flag = 1;
        n = 9;
      }
      res = res * 10 + n;
    }
    return res;
  }
  
  vector<int> digit(int num) {
    vector<int> tmp;
    while (num > 0) {
      tmp.push_back(num % 10);
      num /= 10;
    }
    reverse(tmp.begin(), tmp.end());
    return tmp;
  }
};
