class Solution {
public:
  int longestSubsequence(vector<int>& arr, int difference) {
    int res = 1, n = arr.size();
    unordered_map<int, int> mapping;
    
    for (int i = 0; i < n; i++) {
      int tmp = 1;
      if (mapping.find(arr[i] - difference) != mapping.end()) {
        tmp = mapping[arr[i] - difference] + 1;
      }
      mapping[arr[i]] = max(mapping[arr[i]], tmp);
      res = max(res, mapping[arr[i]]);
    }
    
    return res;
  }
};
