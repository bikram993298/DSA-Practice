/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
// we need prev node so that prev->next=current=next;
// but we have not prev so 
// what we can do is that when you encounter node ,,replce its value to its next and,skip the next node 
    void deleteNode(ListNode* node) {
        node->val=node->next->val;
        node->next=node->next->next;
        
    }
};