class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode* first = head;
        ListNode* second = head->next;
        ListNode* prev = NULL;

        head = second;

        while(first && second){
            ListNode* third = second->next;

            second->next = first;
            first->next = third;

            if(prev) prev->next = second;

            prev = first;
            first = third;
            if(third) second = third->next;
        }
        return head;
    }
};