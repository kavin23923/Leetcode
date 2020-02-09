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
  ListNode *detectCycle(ListNode *head) {
    if (!head || !head->next) return NULL;
    ListNode *fast = head, *slow = head;
    while (fast && fast->next) {
      fast = fast->next->next;
      slow = slow->next;
      if (slow == fast) break; 
    }
    return slow == fast ? cycleBegin(head, fast) : NULL;
  }

  ListNode *cycleBegin(ListNode *head, ListNode *ln) {
    while (head != ln) {
      head = head->next;
      ln = ln->next;
    }
    return ln;
  }
};
