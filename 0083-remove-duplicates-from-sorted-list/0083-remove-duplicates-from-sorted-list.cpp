class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head) return head;

        ListNode* curr = head;
        // when you compare two nodes check cuure && curr->next  exist

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