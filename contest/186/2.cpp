class Solution {
public:
  int maxScore(vector<int>& cardPoints, int k) {
    int score = 0;
    int size = cardPoints.size();
    vector<int> prefix(size + 1, 0);
    vector<int> suffix(size + 1, 0);
    
    for(int i = 1; i <= size; i++) {
      prefix[i] = prefix[i - 1] + cardPoints[i - 1]; 
    }
    for(int i = 1; i <= size; i++) {
      suffix[i] = suffix[i - 1] + cardPoints[size - i]; 
    }
    for (int i = 0; i <= k; i++) {
      score = max(score, prefix[i] + suffix[k - i]);
    }
    
    return score;
  }
};
