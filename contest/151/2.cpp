class Solution {
public:
  vector<int> numSmallerByFrequency(vector<string>& queries, vector<string>& words) {
    vector<int> res;
    vector<int> count;
    
    for (string &w : words) {
      count.push_back(calculate(w));
    }
    
    for (int i = 0; i < queries.size(); i++) {
      int now = calculate(queries[i]);
      int tmp = 0;
      for (int j = 0; j < count.size(); j++) {
        if (count[j] > now) tmp++;
      }
      res.push_back(tmp);
    }
    
    return res;
  }
  
  int calculate(string str) {
    map<char, int> count;
    for (char c : str) {
      count[c]++;
    }
    return count.begin()->second;
  }
};
