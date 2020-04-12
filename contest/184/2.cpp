class Solution {
public:
  vector<int> processQueries(vector<int>& queries, int m) {
    vector<int> res;
    stack<int> permute;
    stack<int> tmp;
    int pos;
    
    for (int i = m; i > 0; i--) {
      permute.push(i);
    }
    for (int q : queries) {
      pos = 0;
      while (q != permute.top()){
        tmp.push(permute.top());
        permute.pop();
        pos++;
      }
      permute.pop();
      res.push_back(pos);
      while (!tmp.empty()) {
        permute.push(tmp.top());
        tmp.pop();
      }
      permute.push(q);
    }
    return res;
  }
};
