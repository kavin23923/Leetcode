class Solution {
public:
  int evalRPN(vector<string>& tokens) {
    stack<int> num;
    int num1, num2;
    for (string s : tokens) {
      if (s == "+" || s == "-" || s == "*" || s == "/") {
        num2 = num.top();
        num.pop();
        num1 = num.top();
        num.pop();
        if (s == "+") {
          num.push(num1 + num2);
        } else if (s == "-") {
          num.push(num1 - num2);
        } else if (s == "*") {
          num.push(num1 * num2);
        } else {
          num.push(num1 / num2);
        }
      } else {
        num.push(stoi(s));
      }     
    }
    return num.top();
  }
};
