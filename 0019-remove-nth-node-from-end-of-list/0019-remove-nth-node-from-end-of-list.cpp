class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* fast = dummy;
        ListNode* slow = dummy;

//         We keep a gap of n nodes between fast and slow.

// When fast reaches end,
// slow will automatically reach node before deletion node.

        // move fast n steps ahead
        for(int i = 0; i < n; i++) {
            fast = fast->next;
        }

        // move both together
        while(fast->next) {
            fast = fast->next;
            slow = slow->next;
        }

        // delete node
        slow->next = slow->next->next;

        return dummy->next;
    }
};