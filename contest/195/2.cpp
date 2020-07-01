class Solution {
public:
  bool canArrange(vector<int>& arr, int k) {
    unordered_map<int, int> mod;
    
    for (int a : arr) {
      if (a < 0) a = a + (abs(a / k) + 1) * k;
      mod[a % k]++;
    }
    
    for (auto it = mod.begin(); it != mod.end(); it++) {
      if (it->first == 0 && it->second % 2 != 0) {
        return false;
      } else if (it->first * 2 == k && it->second % 2 != 0) {
        return false;
      } else if (it->first != 0 && it->second != mod[k - it->first]) {
        return false;
      }
    }
    
    return true;
  }
};
