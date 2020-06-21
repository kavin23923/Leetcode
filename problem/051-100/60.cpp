class Solution {
public:
  string getPermutation(int n, int k) {
    string res = "";
    vector<int> num;
    vector<int> mul = {1};
    
    for (int i = 1; i <= n; i++) {
      num.push_back(i);
      mul.push_back(mul.back() * i);
    }
    
    k--;
    for (int i = n - 1; i >= 0; i--) {
      int target = k / mul[i];
      res += '0' + num[target];
      num.erase(num.begin() + target);
      k %= mul[i];
    }
    
    return res;
  }
};
