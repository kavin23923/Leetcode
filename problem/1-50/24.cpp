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
  ListNode* swapPairs(ListNode* head) {
    ListNode *new_head = new ListNode(-1);
    ListNode *now = new_head;
    ListNode *tmp;
  
    now->next = head;
    while (now->next && now->next->next) {
      tmp = now->next;
      now->next = now->next->next;
      tmp->next = now->next->next;
      now->next->next = tmp;
      now = now->next->next;
    }

    head = new_head->next;
    delete new_head;
    return head;
  }
};
