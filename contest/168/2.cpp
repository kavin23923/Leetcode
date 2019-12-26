class Solution {
public:
  bool isPossibleDivide(vector<int>& nums, int k) {
    if (nums.size() % k != 0) return false;
    
    map<int, int> count;
    int i, amount;
    for (i = 0; i < nums.size(); i++) {
      count[nums[i]]++;
    }
    
    for (auto it = count.begin(); it != count.end(); it++) {
      if (it->second > 0) {
        amount = it->second;
        for (i = 0; i < k; i++) {
          if (count.find(it->first + i) == count.end() || count[it->first + i] < it->second) {
            return false;
          }
          count[it->first + i] -= amount;
        }
      }
    }

    return true;
  }
};