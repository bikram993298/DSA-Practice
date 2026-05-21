class Solution {
public:
    bool hasCycle(ListNode *head) {
        // if (!head || !head->next)
        //     return false;

        ListNode* slow = head;
        ListNode* fast = head;
        // necause you are going fast->next-> next so you hae to chekc fst->next should exicts to overcoem segmentatio so this cehck..alwasy use chek what yo are accesign accoridn t othat access

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return true;
        }

        return false;
    }
};