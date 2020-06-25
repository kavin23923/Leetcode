class Solution {
public:
  int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
    int round = 1, len = beginWord.size();
    unordered_set<string> word(wordList.begin(), wordList.end());
    queue<string> target;
    string tmp;
    
    if (word.find(endWord) == word.end()) return 0;
    
    target.push(beginWord);
    while (!target.empty()) {
      int size = target.size();
      for (int i = 0; i < size; i++) {
        tmp = target.front();
        target.pop();
        if (tmp == endWord) return round;
        for (int j = 0; j < len; j++) {
          char old = tmp[j];
          for (int k = 0; k < 26; k++) {
            tmp[j] = k + 'a';
            if (word.find(tmp) != word.end()) {
              word.erase(tmp);
              target.push(tmp);
            }
          }
          tmp[j] = old;
        }
      }
      round++;
    }
    
    return 0;
  }
};
