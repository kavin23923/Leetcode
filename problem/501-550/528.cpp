class Solution {
public:
  Solution(vector<int>& w) {
    sum.push_back(w[0]);
    for(int i = 1; i < w.size(); i++) {
      sum.push_back(sum.back() + w[i]);
    }
  }
    
  int pickIndex() {
    int target = rand() % sum.back() + 1;
    int l = 0, r = sum.size() - 1, m;
    while (l < r) {
      m = l + (r - l) / 2;
      if (sum[m] >= target) {
        r = m;
      } else {
        l = m + 1;
      }
    }
    return l;
  }
private:
  vector<int> sum;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
