class Solution {
public:
  int findLucky(vector<int>& arr) {
    int res = -1;
    map<int, int> freq;
    
    for (int num : arr) {
      freq[num]++;
    }
    
    for (auto it = freq.begin(); it != freq.end(); it++) {
      if (it->first == it->second) {
        res = it->first;
      }
    }
    
    return res;
  }
};
