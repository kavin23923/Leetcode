/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
  bool isSubPath(ListNode* head, TreeNode* root) {
    if (!head) {
      return true;
    } else if (!root){
      return false;
    }
    return isSubPathFromRoot(head, root) || isSubPath(head, root->left) || isSubPath(head, root->right);
  }
  
  bool isSubPathFromRoot(ListNode* head, TreeNode* root) {
    if (!head) {
      return true;
    } else if (!root) {
      return false;
    }
    if (head->val != root->val) {
      return false;
    } else {
      return isSubPathFromRoot(head->next, root->left) || isSubPathFromRoot(head->next, root->right);
    }
  }
};
