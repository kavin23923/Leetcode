class Solution {
public:
  bool canReach(vector<int>& arr, int start) {
    if (start < 0 || start >= arr.size()) {
      return false;
    } else if (arr[start] == 0) {
      return true;
    } else if (arr[start] == -1) {
      return false;
    }
    
    int step = arr[start];
    arr[start] = -1;
    return canReach(arr, start - step) || canReach(arr, start + step);
  }
};