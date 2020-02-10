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
  ListNode* partition(ListNode* head, int x) {
    ListNode *first_head = new ListNode(-1);
    ListNode *second_head = new ListNode(-1);
    ListNode *first = first_head;
    ListNode *second = second_head;

    while (head) {
      if (head->val < x) {
        first->next = head;
        first = first->next;
      } else {
        second->next = head;
        second = second->next;
      }
      head = head->next;
    }

    first->next = second_head->next;
    second->next = NULL;
    head = first_head->next;

    delete first_head;
    delete second_head;
    return head;      
  }
};
