//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(!head || !(head->next))
            return NULL;
        
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                break;
        }
        // main thing when you find slow == fast the you got cycle
  // No cycle after slow fast not eqa ,,means no cyycle straight
    if(slow != fast) return NULL;
      
        ListNode* entry = head;
        // slow will be in clylce so not null 
        while(entry != slow) {
            entry = entry->next;
            slow  = slow->next;
        }
        return entry;
    }
};