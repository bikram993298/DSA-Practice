class Solution {
public:
    ListNode* reverse(ListNode* head, int k) {
        ListNode* prev = NULL;
        ListNode* curr = head;

        while(k--) {
            ListNode* next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }

    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;

        ListNode* prev = dummy;
        ListNode* curr = head;

        int groupSize = 1;

        while(curr) {
            // Step 1: count actual nodes in group
            ListNode* temp = curr;
            int count = 0;

            while(temp && count < groupSize) {
                temp = temp->next;
                count++;
            }

            // Step 2: if even → reverse
            if(count % 2 == 0) {
                ListNode* nextGroup = temp;

                // reverse current group
                ListNode* newHead = reverse(curr, count);

                prev->next = newHead;
                curr->next = nextGroup;

                prev = curr;
                curr = nextGroup;
            } 
            else {
                // skip group
                for(int i = 0; i < count; i++) {
                    prev = curr;
                    curr = curr->next;
                }
            }

            groupSize++;
        }

        return dummy->next;
    }
};