class Solution {
public:
  vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    unordered_set<int> exist;
    unordered_set<int> res;
    vector<int> resv;
    
    for (int num : nums1) {
      exist.insert(num);
    }
    for (int num : nums2) {
      if (exist.find(num) != exist.end()) {
        res.insert(num);
      }
    }
    for (auto it = res.begin(); it != res.end(); it++) {
      resv.push_back(*it);
    }
    
    return resv;
  }
};
