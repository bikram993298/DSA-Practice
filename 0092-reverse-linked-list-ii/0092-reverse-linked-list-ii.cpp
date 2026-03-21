class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(!head || left == right) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        
        ListNode* prev = dummy;
        
        // Step 1: move prev to (left-1)
        for(int i = 1; i < left; i++) {
            prev = prev->next;
        }
        
        // Step 2: reverse
        ListNode* curr = prev->next;
        
        for(int i = 0; i < right - left; i++) {
            ListNode* temp = curr->next;

            //here what we are doing we are oushing into the front
            // 12 3 4 5
            // 1 3 2 4 5
            // 1 4 3 2 5
            // 1 5 4 3 2
            
            curr->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
        }
        
        return dummy->next;
    }
};


// class Solution {
// public:

//     ListNode* reverseList(ListNode* head) {
//         ListNode* prev = NULL;
//         ListNode* curr = head;

//         while(curr) {
//             ListNode* temp = curr->next;
//             curr->next = prev;
//             prev = curr;
//             curr = temp;
//         }
//         return prev;
//     }

//     ListNode* reverseBetween(ListNode* head, int left, int right) {
//         if(!head || left == right) return head;

//         ListNode* dummy = new ListNode(0);
//         dummy->next = head;

//         ListNode* prev = dummy;

//         // move to (left-1)
//         for(int i = 1; i < left; i++) {
//             prev = prev->next;
//         }

//         ListNode* start = prev->next;      // left node
//         ListNode* end = start;

//         // move to right
//         for(int i = left; i < right; i++) {
//             end = end->next;
//         }

//         ListNode* nextPart = end->next;

//         // cut
//         prev->next = NULL;
//         end->next = NULL;

//         // reverse
//         ListNode* newHead = reverseList(start);

//         // reconnect
//         prev->next = newHead;
//         start->next = nextPart;

//         return dummy->next;
//     }
// };