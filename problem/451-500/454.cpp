class Solution {
public:
	int fourSumCount(vector<int>& A, vector<int>& B, vector<int>& C, vector<int>& D) {
		unordered_map<int, int> count;
		int size = A.size();
		int res = 0;
		int i, j;
		int sum;
		for (i = 0; i < size; i++) {
			for (j = 0; j < size; j++) {
				count[-(A[i] + B[j])]++;
			}
		}
		for (i = 0; i < size; i++) {
			for (j = 0; j < size; j++) {
				sum = C[i] + D[j];
				if (count.find(sum) != count.end()) {
					res += count[sum];
				}
			}
		}
		return res;
	}
};
