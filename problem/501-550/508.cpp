/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	vector<int> findFrequentTreeSum(TreeNode* root) {
		vector<int> res;
		unordered_map<int, int> count;
		int freq = 0;
		traverse(root, count, &freq);		
    for (auto it = count.begin(); it != count.end(); it++) {
      if (it->second == freq) {
        res.push_back(it->first);
      }
    }
		return res;
  }

	int traverse(TreeNode* root, unordered_map<int, int> &count, int *freq) {
		if (!root) return 0;
		int l = traverse(root->left, count, freq);
		int r = traverse(root->right, count, freq);
		int sum = l + r + root->val;
		count[sum]++;
		*freq = max(count[sum], *freq);
		return sum;
	}
};