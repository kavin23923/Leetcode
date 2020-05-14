class Solution {
public:
  bool isPerfectSquare(int num) {
    for (int i = 1; num / i >= i; i++) {
      if (num % i == 0 && num / i == i) return true;
    }
    return false;      
  }
};
