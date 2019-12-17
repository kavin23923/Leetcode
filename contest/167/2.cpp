class Solution {
public:
  vector<int> sequentialDigits(int low, int high) {
    vector<int> res;
    int len1 = to_string(low).size();
    int len2 = min((int)to_string(high).size(), 9);
    int i;
    for (i = len1; i <= len2; i++) {
      generateDigits(low, high, i, res);
    } 
    return res;
  }
  
  void generateDigits(int low, int high, int len, vector<int>& res) {
    int now = 0;
    int add = 0;
    prepare(len, &now, &add);
    while (now <= high) {
      if (now >= low && now <= high) {
        res.push_back(now);
      }
      if (now % 10 == 9) {
        break;
      }
      now += add;
    }
  }
  
  void prepare(int len, int* now, int* add) {
    for (int i = 0; i < len; i++) {
      *now = *now * 10 + i + 1;
      *add = *add * 10 + 1;
    }
  }
};