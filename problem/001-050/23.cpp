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
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    return merge(lists, 0 , lists.size() - 1);
  }

  ListNode* merge(vector<ListNode*>& lists, int start, int end) {
    if (start == end) {
      return lists[start];
    } else if (start > end) {
      return NULL;
    }

    int mid = start + (end - start) / 2;
    ListNode *first = merge(lists, start, mid);
    ListNode *second = merge(lists, mid + 1, end);
    ListNode *head, *cur;
    
    if (!first) return second;
    if (!second) return first;
    if (first->val < second->val) {
      head = first;
      first = first->next;
    } else {
      head = second;
      second = second->next;
    }
    
    cur = head;
    while (first && second) {
      if (first->val < second->val) {
        cur->next = first;
        first = first->next;
      } else {
        cur->next = second;
        second = second->next;
      }
      cur = cur->next;
    }
    cur->next = first ? first : second;
    
    return head;
  }
};
/**
 * This approach is based on divide-and-conquer. 
 * The time complexity is O(NlogK), and the space complexity is O(1).
 * Another approach is using prioity queue to compare all heads of all linked lists.
 * The time complexity is the same, and the implementation is easier. But the space complexity is O(K).
 */
