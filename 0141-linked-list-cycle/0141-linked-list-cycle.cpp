class Solution {
public:
    bool hasCycle(ListNode *head) {
        // if (!head || !head->next)
        //     return false;

        ListNode* slow = head;
        ListNode* fast = head;
        // necause you are going fast->next-> next so you hae to chekc fst->next should exicts to overcoem segmentatio so this cehck..alwasy use chek what yo are accesign accoridn t othat access
        // resaon is if there is cicirular loop then fast and fast nest never null and it slow and fast both wil l enter circle contutnue circural rtrack now fast going 2 times so it willdefiantely catch,,
        // othersies no loop fast will go 2 usnit and eventually raweach edn

        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
                return true;
        }

        return false;
    }
};