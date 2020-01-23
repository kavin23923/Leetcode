class Solution {
public:
  char findTheDifference(string s, string t) {
    int count[26] = {0};
    int len = s.length();
    int i;
    char res;

    for (i = 0; i < len; i++) {
	    count[s[i] - 'a']++;
    }
    for (i = 0; i < len + 1; i++) {
      if (--count[t[i] - 'a'] < 0) {
        res = t[i];
        break;
	    }
    }
    return res;
  }
};