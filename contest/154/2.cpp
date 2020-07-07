class Solution {
public:
  string reverseParentheses(string s) {
    stack<string> word;
    string tmp, res;
    
    word.push("");
    for (char c : s) {
      if (c == '(') {
        word.push("");
      } else if (c == ')') {
        tmp = word.top();
        word.pop();
        reverse(tmp.begin(), tmp.end());
        word.top() += tmp;
      } else {
        word.top() += c;
      }
    }
    
    return word.top();
  }
};
