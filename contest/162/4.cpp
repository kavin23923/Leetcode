class Solution {
public:
  int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
    res = 0;
    int n = words.size();
    vector<vector<int>> count;
    vector<int> letter(26);
    vector<int> now(26);
    
    for (char c : letters) {
      letter[c - 'a']++; 
    }
    for (string s : words) {
      vector<int> tmp(26);
      for (char c : s) {
        tmp[c - 'a']++;
      }
      count.push_back(tmp);
    }
    bruteForce(count, letter, now, score, 0);
    return res;
  }
  
  void bruteForce(vector<vector<int>> &count, vector<int> &letter, vector<int> now, vector<int>& score, int target) {
    if (target == count.size()) {
      res = max(res, valid(now, letter, score));
      return;
    }
    bruteForce(count, letter, now, score, target + 1);
    for (int i = 0; i < 26; i++) {
      now[i] += count[target][i];
    }
    bruteForce(count, letter, now, score, target + 1);
  }
  
  int valid(vector<int> &now, vector<int> &letter, vector<int>& score) {
    int sum = 0;
    for (int i = 0; i < 26; i++) {
      if (letter[i] < now[i]) return -1;
      sum += now[i] * score[i];
    }
    return sum;
  }
  
private:
  int res;
};
