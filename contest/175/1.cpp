class Solution {
public:
  bool checkIfExist(vector<int>& arr) {
    unordered_set<int> exist;
    for (auto num : arr) {
      if (exist.find(num * 2) != exist.end()) {
        return true;
      } else if (num % 2 == 0 && exist.find(num / 2) != exist.end()) {
        return true;
      }
      exist.insert(num);
    }
    return false;
  }
};
