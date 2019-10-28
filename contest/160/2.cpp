class Solution {
public:
  vector<int> circularPermutation(int n, int start) {
    vector<int> tmp{start};
    unordered_set<int> used{start};
    permutation(tmp, n, used);
    return res;
  }
  
  bool permutation(vector<int> tmp, int n, unordered_set<int> used) {
    if (tmp.size() == (int) pow(2, n)) {
      if (diff(tmp[0], tmp[(int) pow(2, n) - 1], n)) {
        res = tmp;
        return true;
      } else {
        return false;
      }
    }
    int last = tmp[tmp.size() - 1];
    for (int i = 0; i < n; i++) {
      int now = last ^ (1 << i);
      if (used.find(now) == used.end()) {
        tmp.push_back(now);
        used.insert(now);
        if (permutation(tmp, n, used)) {
          return true;
        }
        tmp.pop_back();
        used.erase(now);
      }
    } 
    return false;
  }
  
  bool diff(int num1, int num2, int n) {
    int count = 0;
    for (int i = 0; i < n; i++) {
      count += ((num1 & 1) == (num2 & 1)) ? 0 : 1;
      if (count > 1) return false;
      num1 >>= 1;
      num2 >>= 1;
    }
    return count == 1;
  }
  
private: 
  vector<int> res;
};