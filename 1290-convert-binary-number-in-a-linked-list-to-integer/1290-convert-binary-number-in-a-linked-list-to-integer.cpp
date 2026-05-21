class Solution {
public:
    int getDecimalValue(ListNode* head) {

        int num = 0;

        while(head) {

            num = num * 2 + head->val;
            //left to right contrucution into by 2 then+headval

            head = head->next;
        }

        return num;
    }
};