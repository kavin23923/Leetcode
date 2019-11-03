class Solution {
public:
  string minRemoveToMakeValid(string s) {
    stack<Par> remove;
    int size = s.length();
    for (int i = 0; i < size; i++) {
      if (s[i] == '(' || s[i] == ')') {
        if (!remove.empty() && s[i] == ')' && remove.top().symbol == '(') {
          remove.pop();
        } else {
          Par par = {i, s[i]};
          remove.push(par);
        }
      }
    }
    while (!remove.empty()) {
      s.erase(s.begin() + remove.top().pos);
      remove.pop();
    }
    return s;
  }
private:
  struct Par{
    int pos;
    char symbol;
  };
};