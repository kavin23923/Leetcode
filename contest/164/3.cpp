class Solution {
public:
  vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
    set<string> product(products.begin(), products.end());
    vector<vector<string>> res;
    int len = searchWord.size();
    string tmp;
    
    for (int i = 0; i < len; i++) {
      vector<string> round;
      set<string> next_product;
      for (auto it = product.begin(); it != product.end(); it++) {
        tmp = *it;
        if (tmp.size() > i && tmp[i] == searchWord[i]) {
          next_product.insert(tmp);
          if (round.size() < 3) round.push_back(tmp);
        }
      } 
      res.push_back(round);
      product = next_product;
    }
    
    return res;
  }
};
