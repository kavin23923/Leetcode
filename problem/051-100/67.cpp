class Solution {
public:
  string addBinary(string a, string b) {
    string res = "";
    int now1 = a.size() - 1, now2 = b.size() - 1;
    int tmp1, tmp2, carry = 0, sum;
    
    while (now1 >= 0 || now2 >= 0) {
      tmp1 = now1 >= 0 ? a[now1--] - '0' : 0;
      tmp2 = now2 >= 0 ? b[now2--] - '0' : 0;
      sum = carry + tmp1 + tmp2;
      carry = sum / 2;
      res += (sum % 2) + '0';
    }
    if (carry) res += '1';
    
    reverse(res.begin(), res.end());
    return res;
  }
};
