class Solution {
public:
  int minFlips(int a, int b, int c) {
    vector<int> binary_a = binary(a);
    vector<int> binary_b = binary(b);
    vector<int> binary_c = binary(c);
    int size = max(binary_a.size(), max(binary_b.size(), binary_c.size()));
    binary_a.resize(size);
    binary_b.resize(size);
    binary_c.resize(size);
    int res = 0;
    for (int i = 0; i < size; i++) {
      if (binary_c[i] == 0) {
        if (binary_a[i] == 1) res++;
        if (binary_b[i] == 1) res++;
      } else {
        if (binary_a[i] == 0 && binary_b[i] == 0) {
          res++;
        }
      }
    }
    return res;
  }
  
  vector<int> binary(int num) {
    vector<int> tmp;
    while (num > 0) {
      tmp.push_back(num & 1);
      num >>= 1;
    }
    return tmp;
  }
};
