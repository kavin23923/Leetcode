class Solution {
public:
  vector<int> getStrongest(vector<int>& arr, int k) {
    int size = arr.size();
    sort(arr.begin(), arr.end());
    int median = arr[(size - 1) / 2];
    auto cmp = [median](int a, int b) {
      return abs(a - median) == abs(b - median) ? a > b : abs(a - median) > abs(b - median);
    };
    sort(arr.begin(), arr.end(), cmp);
    vector<int> res(arr.begin(), arr.begin() + k);
    return res;
  }
};
