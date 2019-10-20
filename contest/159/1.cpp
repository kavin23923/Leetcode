class Solution {
public:
  bool checkStraightLine(vector<vector<int>>& coordinates) {
    bool flag = coordinates[1][0] == coordinates[0][0] ? true : false;
    float val = flag == true ? 0 : (coordinates[1][1] - coordinates[0][1]) / (coordinates[1][0] - coordinates[0][0]);
    for (int i = 1; i < coordinates.size() - 1; i++) {
      if (coordinates[i + 1][0] == coordinates[i][0] && !flag) {
        return false;
      } else if (((float)coordinates[i + 1][1] - coordinates[i][1]) / (coordinates[i + 1][0] - coordinates[i][0]) != val) {
        return false;
      }
    }
    return true;
  }
};
