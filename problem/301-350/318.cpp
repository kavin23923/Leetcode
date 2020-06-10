class Solution {
public:
  int maxProduct(vector<string>& words) {
    int size = words.size();
    int res = 0;
    int tmp = 0;
    vector<int> code;
    
    for (int i = 0; i < size; i++, tmp = 0) {
      for (int j = 0; j < words[i].size(); j++) {
        tmp |= (1 << (words[i][j] - 'a'));
      }
      code.push_back(tmp);
    }
    
    for (int i = 0; i < size; i++) {
      for (int j = i + 1; j < size; j++) {
        if ((code[i] & code[j]) == 0) {
          res = max(res, (int)(words[i].size() * words[j].size()));
        }
      }
    }
    return res;
  }
};
