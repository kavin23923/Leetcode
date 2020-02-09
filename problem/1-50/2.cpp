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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    ListNode *tmp = new ListNode(-1);
    ListNode *cur = tmp;
    int pre = 0, num1, num2, sum;
    while (l1 || l2) {
      if (l1) {
        num1 = l1->val;
        l1 = l1->next;
      } else {
        num1 = 0;
      }
      if (l2) {
        num2 = l2->val;
        l2 = l2->next;
      } else {
        num2 = 0;
      }
      sum = num1 + num2 + pre;
      ListNode *now = new ListNode(sum % 10);
      pre = sum / 10;
      cur->next = now;
      cur = cur->next;
    }
    if (pre) cur->next = new ListNode(1);
    ListNode *head = tmp->next;
    delete tmp;
    return head;
  }
};
