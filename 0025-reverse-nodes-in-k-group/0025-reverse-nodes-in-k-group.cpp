class Solution {
public:

    ListNode* reverseKGroup(ListNode* head, int k) {

        ListNode* temp = head;
        
        // check if k nodes exist
        for(int i=0;i<k;i++){
            if(!temp) return head;
            temp = temp->next;
        }

        // reverse first k nodes
        ListNode* prev = NULL;
        ListNode* curr = head;

        for(int i=0;i<k;i++){

            ListNode* nxt = curr->next;

            curr->next = prev;

            prev = curr;
            curr = nxt;
        }

        // head becomes last after reverse
        // connect remaining list
        // this is importatn head is predifeined
        head->next = reverseKGroup(curr,k);

        return prev;
    }
};