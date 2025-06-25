class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode dummy(0);        // Dummy node to handle head reversals
        dummy.next = head;
        ListNode* prev = &dummy;

        // Step 1: Move `prev` to the node just before `left`
        for (int i = 1; i < left; i++) {
            prev = prev->next;
        }

        // Step 2: Reverse sublist from `left` to `right`
        ListNode* curr = prev->next;
        ListNode* next = nullptr;
        for (int i = 0; i < right - left; i++) {
            next = curr->next;
            curr->next = next->next;
            next->next = prev->next;
            prev->next = next;
        }

        return dummy.next;
    }
};
