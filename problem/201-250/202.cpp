class Solution {
public:
  bool isHappy(int n) {
    unordered_set<int> exist;
    while (n != 1) {
      n = calculate(n);
      if (exist.find(n) != exist.end()) {
        break;
      }
      exist.insert(n);
    }
    return n == 1;
  }
  
  int calculate(int n) {
    int res = 0, tmp;
    while (n > 0) {
      tmp = n % 10;
      n /= 10;
      res += tmp * tmp;
    }
    return res;
  }
};

/**
 * Can use Floyd's Cycle detection algorithm (two pointers)
 *
 * class Solution {
 * public:
 *   bool isHappy(int n) {
 *     int fast = n, slow = n;
 *     while (fast != 1 && slow != 1) {
 *       fast = calculate(calculate(fast));
 *       slow = calculate(slow);
 *       if (fast == slow) {
 *         break;
 *       }
 *     }
 *     return fast == 1;
 *   }
 *
 *   int calculate(int n) {
 *     int res = 0, tmp;
 *     while (n > 0) {
 *       tmp = n % 10;
 *       n /= 10;
 *       res += tmp * tmp;
 *     }
 *     return res;
 *   }
 * };
 */
