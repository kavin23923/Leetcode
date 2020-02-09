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
  ListNode* oddEvenList(ListNode* head) {
    if (!head) return head;
    ListNode *even_head = head->next;
    ListNode *even = even_head;
    ListNode *odd = head;
    while (even && even->next) {
      odd->next = even->next;
      even->next = even->next->next;
      even = even->next;
      odd = odd->next;
    }
    odd->next = even_head;
    return head;
  }
};

/**
 * For linked list problem, think about any approach without newing a redundant node.
 * It may give you a better solution.
 */
