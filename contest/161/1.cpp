class Solution {
public:
  int minimumSwap(string s1, string s2) {
    int res = 0; 
    int size = s1.length();
    vector<int> diff;
    for (int i = 0; i < size; i++) {
      if (s1[i] != s2[i]) {
        diff.push_back(i);
      }
    }
    int i = 0;
    while (i < diff.size()) {
      bool flag = false; 
      for (int j = i + 1; j < diff.size(); j++) {
        int p1 = diff[i];
        int p2 = diff[j];
        if (s1[p1] != s2[p2]) {
          res++;
          diff.erase(diff.begin() + j);
          diff.erase(diff.begin() + i);
          flag = true;
          break;
        }
      }
      if (!flag) {
        i++;
      }
    }
    return diff.size() % 2 == 0 ? res + diff.size() : -1;
  }
};