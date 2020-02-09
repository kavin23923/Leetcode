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
  bool isPalindrome(ListNode* head) {
    if (!head) {
      return true; // empty linked list for true
    } 
    ListNode *mid = head;
    ListNode *fast = head;
    while (fast->next && fast->next->next) {
      fast = fast->next->next;
      mid = mid->next;
    }
    ListNode *half = reverse(mid->next);
    while (half) {
      if (half->val != head->val) {
        return false;
      }
      half = half->next;
      head = head->next;
    }
    return true;
  }

  ListNode* reverse(ListNode* head) {
    ListNode *cur = NULL, *tmp;
    while (head) {
      tmp = head->next;
      head->next = cur;
      cur = head;
      head = tmp;
    }
    return cur;
  }
};
