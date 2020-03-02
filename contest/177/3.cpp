class Solution {
public:
  vector<int> closestDivisors(int num) {
    vector<int> candidate1 = find(num + 1);
    vector<int> candidate2 = find(num + 2);
    int diff1 = abs(candidate1[0] - candidate1[1]);
    int diff2 = abs(candidate2[0] - candidate2[1]);
    return diff1 < diff2 ? candidate1 : candidate2;
  }
  
  vector<int> find(int num) {
    int base = (int) sqrt(num);
    int i = base;
    for (; i >= 1; i--) {
      if (num % i == 0) {
        break;
      }
    }
    vector<int> res{i, num / i};
    return res;
  }
};
