class Solution {
public:
  int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
    long long int res = 0;
    int max_h = 0, max_w = 0;
    sort(horizontalCuts.begin(), horizontalCuts.end());
    sort(verticalCuts.begin(), verticalCuts.end());
    
    for (int i = 0; i <= horizontalCuts.size(); i++) {
      if (i == 0) {
        max_h = max(max_h, horizontalCuts[i] - 0);      
      } else if (i == horizontalCuts.size()) {
        max_h = max(max_h, h - horizontalCuts[i - 1]);
      } else {
        max_h = max(max_h, horizontalCuts[i] - horizontalCuts[i - 1]); 
      }
    }
    
    for (int i = 0; i <= verticalCuts.size(); i++) {
      if (i == 0) {
        max_w = max(max_w, verticalCuts[i] - 0);      
      } else if (i == verticalCuts.size()) {
        max_w = max(max_w, w - verticalCuts[i - 1]);
      } else {
        max_w = max(max_w, verticalCuts[i] - verticalCuts[i - 1]); 
      }
    }
    
    res = ((long long)max_h * max_w) % (1000000007);
    return (int)res;
  }
};
