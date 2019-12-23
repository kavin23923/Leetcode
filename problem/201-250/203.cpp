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
  ListNode* removeElements(ListNode* head, int val) {
    ListNode *new_head = new ListNode(-1);
    ListNode *now = new_head;
    now->next = head;
    while (now->next) {
      if (now->next->val == val) {
        now->next = now->next->next;
      } else {
        now = now->next;
      }
    }
    head = new_head->next;
    delete new_head;
    return head;
  }
};
