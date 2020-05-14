class Solution {
public:
  int findJudge(int N, vector<vector<int>>& trust) {
    vector<int> be_trust(N + 1);
    vector<int> count(N+1);
    
    for (vector<int>& v : trust) {
      count[v[0]]++;
      be_trust[v[1]]++;
    }
    
    for (int i = 1; i <= N; i++) {
      if (be_trust[i] == N - 1 && count[i] == 0) return i;
    }
    
    return -1;
  }
};
