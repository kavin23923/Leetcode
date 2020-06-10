class Solution {
public:
  int subarrayBitwiseORs(vector<int>& A) {
    unordered_set<int> res, pre, now;
    
    for (int a : A) {
      now = {a};
      for (int p : pre) {
        now.insert(p | a);
      }
      pre = now; // there are at most 32 numbers in now
      res.insert(pre.begin(), pre.end());
    }
    
    return res.size();
  }
};

/**
 * Time complexity is O(32n).
 */
