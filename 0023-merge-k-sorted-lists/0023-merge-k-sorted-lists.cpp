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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        struct cmp {
           // min heap
            bool operator()(ListNode* a, ListNode* b) {
                return a->val > b->val;
                //why min heap mug up 
            }
        };

        priority_queue<ListNode*, vector<ListNode*>, cmp> pq;

        // Push the head of each list into the heap
        for (auto node : lists) {
            if (node)
                pq.push(node);
        }
        // when there is nerge bew ilst n=making use dymmy list
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;
        // tail pointer to build the result list

        while (!pq.empty()) {
            ListNode* node = pq.top();
            pq.pop();

            tail->next = node; // attach the smallest node
            tail = node;       // move tail forward

            if (tail->next)
                pq.push(tail->next); // push next node from same list
        }

        return dummy->next; // return merged list (skip dummy node)
    }
};

// ✅ Final Complexity:

// Time: O(N log k)

// Space: O(k)