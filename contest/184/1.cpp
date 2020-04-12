class Solution {
public:
  vector<string> stringMatching(vector<string>& words) {
    unordered_set<string> substring;
    int size = words.size();
    
    for (int i = 0; i < size; i++) { 
      for (int j = i + 1; j < size; j++) {
        if(words[i].find(words[j]) != string::npos) {
          substring.insert(words[j]);
        } else if (words[j].find(words[i]) != string::npos) {
          substring.insert(words[i]);
        }
      }
    }
    
    vector<string> res(substring.begin(), substring.end());
    return res;
  }
};
