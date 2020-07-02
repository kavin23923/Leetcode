class Solution {
public:
  vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
    vector<vector<int>> res;       
    int n = arr.size();  
    
    sort(arr.begin(), arr.end());
    int now = arr[1] - arr[0];
    
    for (int i = 1; i < n; i++) {
      if (arr[i] - arr[i - 1] < now) {
        now = arr[i] - arr[i - 1];
        res.clear();
        res.push_back({arr[i - 1], arr[i]});
      } else if (arr[i] - arr[i - 1] == now) {
        res.push_back({arr[i - 1], arr[i]});
      }
    }  
    
    return res;
  }
};
