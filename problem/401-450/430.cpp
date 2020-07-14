/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
  Node* flatten(Node* head) {
    for (Node *now = head; now != NULL; now = now->next) {
      if (now->child) {
        // change child to next
        Node* tmp = now->next;
        now->next = now->child;
        now->child->prev = now;
        now->child = NULL;
        Node* final_next = now->next;
        // change original next to child final next
        while (final_next->next) final_next = final_next->next;
        final_next->next = tmp;
        if (tmp) tmp->prev = final_next;
      }
    } 
    return head;
  }
};
