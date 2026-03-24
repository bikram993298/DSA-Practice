class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;
        // where we need we use noramlly dummy
        ListNode* curr = head;

        while(curr) {
            if(curr->next && curr->val == curr->next->val) {
                int val = curr->val;

                while(curr && curr->val == val) {
                    curr = curr->next;
                }
                // go to til ewual coming

                prev->next = curr; // skip all duplicates
            } else {
                prev = curr;
                curr = curr->next;
            }
        }

        return dummy->next;
    }
};