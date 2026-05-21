class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        // base case you should remember
        if(!head || !head->next || k == 0) return head;

        int n = 1;
        ListNode* tail = head;

        while(tail->next) {
            tail = tail->next;
            n++;
        }

        k = k % n;
        if(k == 0) return head;

        tail->next = head; // make circular

        int steps = n - k;
        //  we have to break n-k bond and 

        ListNode* newTail = head;
        // lets think 3 ke bad bond delete karna he so 
        // 1->2->3->4->5 last se 2 roroate means 4-> 5 will forwaard n-2 means ,if u want to go 3 then only move 3-1  times

        for(int i = 0; i < steps-1; i++)
            newTail = newTail->next;

        ListNode* newHead = newTail->next;
        newTail->next = NULL;

        return newHead;
    }
};