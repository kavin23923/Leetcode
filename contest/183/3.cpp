class Solution {
public:
  string longestDiverseString(int a, int b, int c) {
    string res = "";
    vector<pair<int, char>> word; 
    
    auto cmp = [](pair<int, char> &a, pair<int, char> &b) {
      return a.first > b.first;
    };
    word.push_back(make_pair(a, 'a'));
    word.push_back(make_pair(b, 'b'));
    word.push_back(make_pair(c, 'c'));
    
    while (word[0].first > 0 || word[1].first > 0 || word[2].first > 0) {
      sort(word.begin(), word.end(), cmp);
      if (res.size() != 0 && word[0].second == res.back()) {
        break;
      }
      if (word[0].first - word[1].first >= 3 && word[1].first > 0) {
        res = res + word[0].second + word[0].second + word[1].second;
        word[0].first -= 2;
        word[1].first -= 1;
      } else {
        if (word[0].first >= 2) {
          res = res + word[0].second + word[0].second;
          word[0].first -= 2;
        } else if (word[0].first > 0){
          res = res + word[0].second;
          word[0].first -= 1;
        }
        if (word[1].first >= 2) {
          res = res + word[1].second + word[1].second;
          word[1].first -= 2;
        } else if (word[1].first > 0){
          res = res + word[1].second;
          word[1].first -= 1;
        }
      }
    }
      
    return res;
  }
};
