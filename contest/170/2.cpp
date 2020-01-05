class Solution {
public:
  vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
    vector<int> res;
    int i;
    int size = arr.size();
    int l;
    int r;
    
    for (i = 1; i < size; i++) {
      arr[i] ^= arr[i - 1];
    }
    
    size = queries.size();
    for (i = 0; i < size; i++) {
      l = queries[i][0] == 0 ? 0 : arr[queries[i][0] - 1];
      r = arr[queries[i][1]];
      res.push_back(r ^ l);
    }
    
    return res;
  }
};