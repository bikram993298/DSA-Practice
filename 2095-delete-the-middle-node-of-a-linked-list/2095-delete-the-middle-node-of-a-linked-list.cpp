class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {

        // single node
        if(head->next == NULL)
            return NULL;

        ListNode* slow = head;
        ListNode* fast = head;
        ListNode* prev = NULL;
        // why to use prev beacuse you got mmiddle now you have to get its previous then change teh connection

        // find middle
        while(fast && fast->next) {

            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }

        // delete middle
        prev->next = prev->next->next;

        return head;
    }
};