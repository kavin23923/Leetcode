class Solution {
public:
  vector<int> prisonAfterNDays(vector<int>& cells, int N) {
    vector<int> first = {-1};
    int count = 0;
    
    while (N-- > 0) {
      vector<int> now(8);
      for (int j = 0; j < 8; j++) {
        if (j == 0 || j == 7 || cells[j - 1] != cells[j + 1]) {
          now[j] = 0;
        } else {
          now[j] = 1;
        }
      }
      if (now == first) {
        N %= count;
      } else if (first[0] == -1) {
        first = now;
      } 
      count++;
      cells = now;
    }
    
    return cells;
  }
};

/**
* We do not need to store all the sequences. Just store the first, and we know it is duplicated. Then use length of cycle to get the answer. 
*/
