class Solution {
public:
  int minNumberOfFrogs(string croakOfFrogs) {
    int res = 1;
    vector<int> count(5);
    
    for (char c : croakOfFrogs) {
      if (c == 'c') {
        count[0]++;
      } else if (c == 'r') {
        if (count[1] == count[0]) {
          return -1;
        }
        count[1]++;
      } else if (c == 'o') {
        if (count[2] == count[0] || count[2] == count[1]) {
          return -1;
        }
        count[2]++;
      } else if (c == 'a') {
        if (count[3] == count[0] || count[3] == count[1] || count[3] == count[2]) {
          return -1;
        }
        count[3]++;
      } else {
        if (count[4] == count[0] || count[4] == count[1] || count[4] == count[2] || count[4] == count[3]) {
          return -1;
        }
        count[4]++;
      }
      res = max(res, count[0] - count[4]);
    }
    
    return count[0] == count[1] && count[1] == count[2] && count[2] == count[3] && count[3] == count[4] ? res : -1; 
  }
};
