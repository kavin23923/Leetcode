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
  ListNode* reverseList(ListNode* head) {
    ListNode *cur = NULL, *tmp;
    while (head) {
      tmp = head->next;
      head->next = cur;
      cur = head;
      head = tmp;
    }
    return cur; 
  }
  
  /**
   * recursion version:
   * ListNode* reverseList(ListNode* head) {
   *   if (!head || !head->next) return head;
   *   ListNode *new_head = reverseList(head->next);
   *   ListNode *tail = head->next;
   *   tail->next = head;
   *   head->next = NULL;
   *   return new_head;
   * }
   */
};
