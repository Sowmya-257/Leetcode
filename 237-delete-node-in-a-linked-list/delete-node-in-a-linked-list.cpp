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
    void deleteNode(ListNode* node) {
        node->val = node->next->val;

        // Store the node to be deleted
        ListNode* temp = node->next;

        // Link the current node to the next of the next node
        node->next = node->next->next;

        // Free the memory of the deleted node
        delete temp;     

    }
};