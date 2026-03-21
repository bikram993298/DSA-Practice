class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode(0);
        ListNode* curr=dummy; 

        int carry=0;

        while(l1 && l2){
            int sum=l1->val+l2->val+carry;
            l1=l1->next;
            l2=l2->next;

            curr->next=new ListNode(sum%10);
            carry=sum/10;
            curr=curr->next;
        }

        while(l1){
            int sum=l1->val+carry;
            curr->next=new ListNode(sum%10);
            carry=sum/10;
            curr=curr->next;
            l1=l1->next;
        }

        while(l2){
            int sum=l2->val+carry;
            curr->next=new ListNode(sum%10);
            carry=sum/10;
            curr=curr->next;
            l2=l2->next;
        }

        if(carry) curr->next=new ListNode(carry);

        return dummy->next;
    }
};