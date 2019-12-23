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
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode *new_head = head;
    ListNode *fast = head;
    ListNode *slow = head;
    int i;
    
    for (i = 0; i < n; i++) {
      fast = fast->next;
    }
    
    if (!fast) {
      new_head = new_head->next;
    } else {
      while (fast->next) {
        fast = fast->next;
        slow = slow->next;
      }
      slow->next = slow->next->next;
    }
    
    return new_head;
  }
};
