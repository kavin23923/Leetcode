class Solution {
public:
  string largestNumber(vector<int>& nums) {
    vector<string> number;
    auto cmp = [](string &a, string &b) {
      return a+b > b+a;
    };
    string res = "";
    
    for (int n : nums) {
      number.push_back(to_string(n));  
    }
    sort(number.begin(), number.end(), cmp);
    
    for (string &s : number) {
      res += s;
    }
    return res[0] == '0' ? "0" : res;
  } 
};
