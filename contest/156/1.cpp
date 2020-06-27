class Solution {
public:
  bool uniqueOccurrences(vector<int>& arr) {
    unordered_set<int> exist;
    unordered_map<int, int> count;
    
    for (int i = 0; i < arr.size(); i++) {
      count[arr[i]]++;
    }
    for(auto it = count.begin(); it != count.end(); it++) {
      if (exist.find(it->second) != exist.end()) {
        return false;
      }
      exist.insert(it->second);
    }
    return true;
  }
};
