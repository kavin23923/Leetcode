class Solution {
public:
  bool isValid(string s) {
    stack<char> symbol;
    
    for (char c : s) {
      if (c == '(' || c == '[' || c == '{') {
        symbol.push(c);
      } else if (c == ')') {
        if (symbol.empty() || symbol.top() != '(') return false;
        symbol.pop();
      } else if (c == ']') {
        if (symbol.empty() || symbol.top() != '[') return false;
        symbol.pop();
      } else {
        if (symbol.empty() || symbol.top() != '{') return false;
        symbol.pop();
      }
    }

    return symbol.empty();
  }
};
