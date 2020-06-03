class Solution {
public:
  vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
    vector<int> res;
    if (tomatoSlices % 2 == 1) return res;
    int j = (tomatoSlices - 2 * cheeseSlices) / 2;
    int s = (4 * cheeseSlices - tomatoSlices) / 2;
    if (j >= 0 && s >= 0) {
      res.push_back(j);
      res.push_back(s);
    }
    return res;
  }
};
