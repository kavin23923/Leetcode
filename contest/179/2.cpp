class Solution {
public:
  int numTimesAllBlue(vector<int>& light) {
    int small = INT_MAX, big = 0;
    int size = light.size();
    int num = 0;
    
    for (int i = 0; i < light.size(); i++) {
      if (light[i] < small) {
        small = light[i];
      } 
      if (light[i] > big) {
        big = light[i];
      }
      if (small == 1 && big - small + 1 == i + 1) {
        num++;
      }
    }
    return num;
  }
};
