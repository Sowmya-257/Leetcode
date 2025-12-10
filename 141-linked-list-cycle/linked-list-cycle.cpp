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
    bool hasCycle(ListNode *head) {
        if (head == nullptr || head->next == nullptr)
            return false;

        ListNode* slow = head;
        ListNode* fast = head;

        while (fast && fast->next) {
            slow = slow->next;             // move slow by 1 step
            fast = fast->next->next;       // move fast by 2 steps

            if (slow == fast)              // cycle detected
                return true;
        }

        return false; // fast reached end → no cycle
    }
};