class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;

        ListNode* curr = head;

        while(curr && curr->next) {
            // eqal same
            if(curr->val == curr->next->val) {
                curr->next = curr->next->next;  // remove duplicate
            } else {
                curr = curr->next;  // move forward
            }
        }

        return head;
    }
};