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
  ListNode* sortList(ListNode* head) {
    if (!head || !head->next) return head;
    ListNode *slow = head;
    ListNode *fast = head;
    while (fast->next && fast->next->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    ListNode *mid = slow->next;
    slow->next = NULL;
    ListNode *l1 = sortList(head);
    ListNode *l2 = sortList(mid);
    return merge(l1, l2);
  }
  
  ListNode* merge(ListNode *l1, ListNode *l2) {
    ListNode *tmp, *head;
    if (l1->val < l2->val) {
      head = l1;
      l1 = l1->next;
    } else {
      head = l2;
      l2 = l2->next;
    }
    
    tmp = head;
    while (l1 && l2) {
      if (l1->val < l2->val) {
        tmp->next = l1;
        l1 = l1->next;
      } else {
        tmp->next = l2;
        l2 = l2->next;
      }
      tmp = tmp->next;
    }
    
    if (l1) {
      tmp->next = l1;
    } else {
      tmp->next = l2;
    }
    
    return head;
  }
};
