class Solution {
public:
  vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> mapping;
    vector<int> tmp;
    vector<int> res;
    int size1 = nums1.size(), size2 = nums2.size();
    
    for (int i = 0; i < size2; i++) {
      while (tmp.size() != 0 && tmp.back() < nums2[i]) {
        mapping[tmp.back()] = nums2[i];
        tmp.pop_back();
      }
      tmp.push_back(nums2[i]);
    }
    
    for (int i = 0; i < size1; i++) {
      if (mapping.find(nums1[i]) != mapping.end()) {
        res.push_back(mapping[nums1[i]]);
      } else {
        res.push_back(-1);
      }
    }
    return res;
  }
};
