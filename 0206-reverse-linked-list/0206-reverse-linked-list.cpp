/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
typedef ListNode* L;

    ListNode* reverseList(ListNode* head) {
        L prev=NULL;
        L curr=head;
        while(curr){
            L temp=curr->next;
            curr->next=prev;
            prev=curr;
            curr=temp;
        }
        /// so the main thing is during reverse head becomes tail and when curr null then prev is he ans
        return prev;
    }
};