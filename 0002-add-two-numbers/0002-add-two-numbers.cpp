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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy=new ListNode(0);
         

         int carry=0;
         ListNode* head=dummy;

         while(l1!=NULL && l2!=NULL){
            int nums=l1->val+l2->val;
            int base=(nums+carry)%10;
           
            ListNode* temp=new ListNode(base);
             carry=(nums+carry)/10;
            head->next=temp;
            l1=l1->next;
            l2=l2->next;
            head=head->next;
            

         }
         while(l1!=NULL){
            int base=(l1->val+carry)%10;
           
            ListNode* temp=new ListNode(base);
             carry=(l1->val+carry)/10;
            head->next=temp;
            head=head->next;
            l1=l1->next;

         }
          while(l2!=NULL){
            int base=(l2->val+carry)%10;
           
            ListNode* temp=new ListNode(base);
             carry=(l2->val+carry)/10;
            head->next=temp;
            head=head->next;
            l2=l2->next;

         }
         if(carry!=0){
            head->next=new ListNode(carry);
         }



         return dummy->next;

        
    }
};