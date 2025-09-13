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
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return false;
        }
        ListNode* slow = head;
        ListNode* fast = head; 
        
        while (fast && fast->next) {
            // So this is Floyd's Cycle Detection alogrithm--was not aware of it before this
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                // cycle was detected
                return true;
            }
        }
        
        // no cycle detected because we broke out
        return false;
    }
};