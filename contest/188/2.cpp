class Solution {
public:
  int countTriplets(vector<int>& arr) {
    int res = 0, size = arr.size();
    
    for (int i = 1; i < size; i++) {
      arr[i] ^= arr[i - 1];
    }
    
    for (int i = 0; i < size; i++) {
      for (int j = i + 1; j < size; j++) {
        for (int k = j; k < size; k++) {
          int a = i == 0 ? arr[j - 1] : arr[j - 1] ^ arr[i - 1];
          int b = arr[k] ^ arr[j - 1];
          if (a == b) res++;
        } 

      }
    }
    
    return res;
  }
};
