// class Solution {
// public:
//     bool isPalindrome(ListNode* head) {
//         vector<int> arr;
        
//         while(head) {
//             arr.push_back(head->val);
//             head = head->next;
//         }
        
//         int l = 0, r = arr.size() - 1;
//         while(l < r) {
//             if(arr[l] != arr[r]) return false;
//             l++; r--;
//         }
        
//         return true;
//     }
// };
class Solution {
public:
    ListNode* reverse(ListNode* head) {
        ListNode* prev = NULL;
        
        while(head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        
        return prev;
    }
    
    bool isPalindrome(ListNode* head) {
        // if(!head || !head->next) return true;
        
        //find middle
        ListNode* slow = head;
        ListNode* fast = head;
        
        while(fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        
     
        ListNode* second = reverse(slow);
        ListNode* first = head;
        
     // second reach last null loop off so econd works
        while(second) {
            if(first->val != second->val) return false;
            first = first->next;
            second = second->next;
        }
        
        return true;
    }
};