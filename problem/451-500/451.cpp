class Solution {
public:
  string frequencySort(string s) {
		unordered_map<char, int> count;
		vector<pair<char, int> > order;
		string res = "";
		
		for (int i = 0; i < s.length(); i++) {
			count[s[i]]++;
		}
		for (auto it = count.begin(); it != count.end(); it++) {
		  order.push_back(make_pair(it->first, it->second));
		}
		auto cmp = [] (pair<char, int> &a, pair<char, int> &b) {return a.second > b.second;};
		sort(order.begin(), order.end(), cmp);
		
		for (int i = 0; i < order.size(); i++) {
		  for (int j = 0; j < order[i].second; j++) {
			  res += order[i].first;
			}
		}
		return res;
  }
};
