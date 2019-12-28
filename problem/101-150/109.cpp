/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
  TreeNode* sortedListToBST(ListNode* head) {
    if (!head) {
      return NULL;
    } else if (!head->next) {
      return new TreeNode(head->val);
    }
    
	// find middle element
    ListNode* mid = head;
    ListNode* fast = head;
    ListNode* pre = NULL;
    while (fast && fast->next) {
      fast = fast->next->next;
      pre = mid;
      mid = mid->next;
    }
    if (pre) {
      pre->next = NULL;
    } 
    
    // build tree
    TreeNode* root = new TreeNode(mid->val);
    root->left = sortedListToBST(head);
    root->right = sortedListToBST(mid->next);
    
	return root;
  }
};

/**
 * 1. No need to create dummy listNode, just use old head pointer.
 *    Otherwise the new and delete operation will add more overhead to the program.
 * 2. No need to create another function.
 */
