class Solution {
public:
  int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
    unordered_map<int, int> count;
    vector<int> num;
    
    for (int a : arr) {
      count[a]++;
    }
    for (auto it = count.begin(); it != count.end(); it++) {
      num.push_back(it->second);
    }
    sort(num.begin(), num.end());
    int i, size = num.size();
    for (i = 0; i < size; i++) {
      if (k < num[i]) {
        break;
      }
      k -= num[i];
    }
    
    return size - i;
  }
};
