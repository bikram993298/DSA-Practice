// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         for (ListNode* a = headA; a != nullptr; a = a->next) {
//             for (ListNode* b = headB; b != nullptr; b = b->next) {
//                 if (a == b) {
//                     return a;
//                 }
//             }
//         }
//         return nullptr;
//     }
// };
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         unordered_set<ListNode*> st;

//         ListNode* curr = headA;
//         while (curr != nullptr) {
//             st.insert(curr);
//             curr = curr->next;
//         }

//         curr = headB;
//         while (curr != nullptr) {
//             if (st.count(curr)) {
//                 return curr;  // intersection found
//             }
//             curr = curr->next;
//         }

//         return nullptr;
//     }
// };
// ⭐ O(n+m)
// ❌ O(n)




class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int lenA = 0, lenB = 0;
        ListNode* a = headA;
        ListNode* b = headB;

        // Calculate lengths
        while (a) {
            lenA++;
            a = a->next;
        }
        while (b) {
            lenB++;
            b = b->next;
        }

        // Reset pointers
        a = headA;
        b = headB;

        // Move the longer list ahead
        while(lenA>lenB){
            lenA--;
            a=a->next;
        }
        while(lenB>lenA){
            lenB--;
            b=b->next;
        }
        // Move both together
        while (a && b) {
            if (a == b) return a;
            a = a->next;
            b = b->next;
        }

        return nullptr;
    }
};
