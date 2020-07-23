/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
  ListNode* removeZeroSumSublists(ListNode* head) {
    unordered_map<int, ListNode*> node;
    ListNode* dump = new ListNode(-1);
    dump->next = head;
    int sum = 0;
    
    node[sum] = dump;
    while (head != NULL) {
      sum += head->val;
      if (node.find(sum) != node.end() && node[sum]->val != -10000) {
        ListNode *tmp = node[sum]->next;
        while (tmp != head) {
          tmp->val = -10000;
          tmp = tmp->next;
        }
        head->val = -10000;
        node[sum]->next = head->next;
      } else {
        node[sum] = head;
      }
      head = head->next;
    }
    
    return dump->next;
  }
};
