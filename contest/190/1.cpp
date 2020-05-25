class Solution {
public:
  int isPrefixOfWord(string sentence, string searchWord) {
    int now = 1;
    int len = sentence.size();
    string tmp = "";
    
    for (int i = 0; i <= len; i++) {
      if (i == len || sentence[i] == ' ') {
        if (judge(tmp, searchWord)) {
          return now;
        }
        tmp = "";
        now++;
      } else {
        tmp += sentence[i];
      }
    }
    return -1;
  }
  
  bool judge(string target, string word) {
    int len = target.size(), now = 0;
    
    for (char c : word) {
      if (now >= len || c != target[now]) {
        return false;
      }
      now++;
    }
    return true;
  }
};
