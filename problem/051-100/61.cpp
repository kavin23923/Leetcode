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
  ListNode* rotateRight(ListNode* head, int k) {
    if (!head) return NULL;
    int len = 1;
    ListNode *cur = head;
    // count len and circle linked list
    while (cur->next) {
      cur = cur->next;
      len++;
    }
    cur->next = head;
    // find new head
    cur = head;
    int target = len - k % len;
    for (int i = 1; i < target; i++) {
      cur = cur->next;
    }
    head = cur->next;
    cur->next = NULL;
    return head;
  }
};
