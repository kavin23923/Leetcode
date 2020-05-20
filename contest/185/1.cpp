class Solution {
public:
  string reformat(string s) {
    string res = "";
    string digit = "";
    string number = "";
    
    for (char c : s) {
      if (c >= 'a' && c <= 'z') {
        digit += c;
      } else {
        number += c;
      }
    }
    if (abs((int)digit.size() - (int)number.size()) <= 1) {
      int now1 = 0, now2 = 0;
      while (now1 < digit.size() && now2 < number.size()) {
        res += digit[now1++]; 
        res += number[now2++];
      }
      if (now1 < digit.size()) {
        res += digit[now1];
      } else if (now2 < number.size()){
        res = number[now2] + res;
      }
    }
    return res;
  }
};
