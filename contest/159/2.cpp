class Solution {
public:
  vector<string> removeSubfolders(vector<string>& folder) {
    sort(folder.begin(), folder.end());
    int now = 0, next = 1;
    vector<string> res{folder[0]};
    while (newt < folder.size()) {
      if (!substring(folder[now], folder[next])) {
        res.push_back(folder[next]);
        now = next;
      }
      next += 1;
    }
    return res;
  }

  bool substring (string target, string input) {
    for (int i = 0; i < target.size(); i++) {
      if (i > input.length() || target[i] != input[i]) {
        return false;
      }
    }
    return input[target.length()] == '/';
  }
};