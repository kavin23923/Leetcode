class Solution {
public:
  bool isPathCrossing(string path) {
    int x = 0, y = 0;
    unordered_set<string> exist;
    
    exist.insert(to_string(x) + "#" + to_string(y));
    for (char c : path) {
      if (c == 'N') {
        x++;
      } else if (c == 'S') {
        x--;
      } else if (c == 'E') {
        y++;
      } else {
        y--;
      }
      string now = to_string(x) + "#" + to_string(y);
      if (exist.find(now) != exist.end()) return true;
      exist.insert(now);
    }
    
    return false;
  }
};
