class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* d = new ListNode(0);
        d->next = head;
        ListNode* prev = d;
        // for easy purpose

        while(prev->next && prev->next->next){
            ListNode* first = prev->next;
            ListNode* second = first->next;
            ListNode* third = second->next;

            second->next = first;
            first->next = third;
            prev->next = second;

            prev = first;
            // partititon think of real life dry run 
            //1 2 3 4
            // 2 1 3 4
            // now prev will be in 1
        }
        return d->next;
    }
};