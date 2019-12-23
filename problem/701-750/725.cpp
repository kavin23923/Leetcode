/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  vector<ListNode*> splitListToParts(ListNode* root, int k) {
    int n = traverseList(root);
    int q = n / k;
    int r = n % k;
    int i, j;
    vector<ListNode*> res;
    
    for (i = 0; i < k; i++) {
      ListNode *tmp = root;
      ListNode *pre;
      int round = q + (i < r ? 1 : 0);
      for (j = 0; j < round; j++) {
        pre = root;
        root = root->next;
        if (j == round - 1) {
          pre->next = NULL;
        }
      }
      res.push_back(tmp);
    }
    
    return res;
  }
  
  int traverseList(ListNode *root) {
    int count = 0;
    while (root) {
      count++;
      root = root->next;
    }
    return count;
  }
};
