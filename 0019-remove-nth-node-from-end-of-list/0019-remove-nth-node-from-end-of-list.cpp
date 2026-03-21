// /**
//  * Definition for singly-linked list.
//  * struct ListNode {
//  *     int val;
//  *     ListNode *next;
//  *     ListNode() : val(0), next(nullptr) {}
//  *     ListNode(int x) : val(x), next(nullptr) {}
//  *     ListNode(int x, ListNode *next) : val(x), next(next) {}
//  * };
//  */
// class Solution {
// public:
//     ListNode* removeNthFromEnd(ListNode* head, int n) {
//            ListNode* dummy = new ListNode(0);
//            dummy->next=head;
//         ListNode* left = dummy;
//         ListNode* right = dummy;

//         while (n > 0) {
//             right = right->next;
//             n--;
//         }

//         while (right->next != nullptr) {
//             left = left->next;
//             right = right->next;
//         }

//         left->next = left->next->next;
//         return dummy->next;
        
//     }
// };

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int len = 0;
        ListNode* t = head;

        while(t){
            len++;
            t = t->next;
        }

        if(len- n==0) return head->next;

        int pos = len - n;
        t = head;

        for(int i = 1; i < pos; i++){
            t = t->next;
        }

        t->next = t->next->next;

        return head;
    }
};