class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
  	vector<int> res;
		int target[26] = {0};
		int now[26] = {0};
		int plen = p.length();
		int slen = s.length();
		int i;

		for (i = 0; i < plen; i++) {
			target[p[i] - 'a']++;
		}
		for (i = 0; i < plen - 1 && i < slen; i++) {
			now[s[i] - 'a']++;
		}
		for (i = plen - 1; i < slen; i++) {
			if (i != plen - 1) now[s[i - plen] - 'a']--;
			now[s[i] - 'a']++;
			if (check(target, now)) {
				res.push_back(i - plen + 1);
			}
		}

		return res;
	}

	bool check(int *target, int *now) {
		int i;
		for (i = 0; i < 26; i++) {
			if (target[i] != now[i]) {
				return false;
			}
		}
		return true;
	}
};
