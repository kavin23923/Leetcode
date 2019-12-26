class Solution {
public:
  int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
    unordered_map<string, int> word_freq;
    int freq = 0;
    int size = s.length();
    int i, j;
    for (i = 0; i < size; i++) {
      int count[26] = {0};
      int letter = 0;
      for (j = 0; j < minSize - 1 && i + j < size; j++) {
        if (++count[s[i + j] - 'a'] == 1) {
          if (++letter > maxLetters) {
            break;
          }
        }
      }
      for (j = 0; j <= maxSize - minSize && i + minSize - 1 + j < size && letter <= maxLetters; j++) {
        if (++count[s[i + minSize - 1 + j] - 'a'] == 1) {
          if (++letter > maxLetters) {
            break;
          }
        }
        string tmp = s.substr(i, minSize + j);
        if (++word_freq[tmp] > freq) {
          freq = word_freq[tmp];
        }
      }
    }
    
    return freq;
  }
};