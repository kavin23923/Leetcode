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
  ListNode* deleteDuplicates(ListNode* head) {
    ListNode* tmp = new ListNode(-1);
    ListNode* cur = tmp;
    cur->next = head;
    while (cur->next && cur->next->next) {
      if (cur->next->val == cur->next->next->val) {
        while (cur->next && cur->next->next && cur->next->val == cur->next->next->val) {
          cur->next->next = cur->next->next->next;
        } 
        cur->next = cur->next->next;
      } else {
        cur = cur->next;
      }
    }
    head = tmp->next;
    delete tmp;
    return head;    
  }
};
