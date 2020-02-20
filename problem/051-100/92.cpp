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
  ListNode* reverseBetween(ListNode* head, int m, int n) {
    ListNode *dummy = new ListNode(-1);
    ListNode *cur = dummy;
    ListNode *reverse = NULL, *tmp, *last;
    dummy->next = head;

    // before m
    for (int i = 1; i < m; i++) {
      cur = cur->next;
    }
    head = cur->next;
    // from m to n
    for (int i = m; i <= n; i++) {
      if (!reverse) last = head;
      tmp = head->next;
      head->next = reverse;
      reverse = head;
      head = tmp;
    }
    // after n
    cur->next = reverse;
    last->next = head;

    head = dummy->next;
    delete dummy;
    return head;
  }
};
