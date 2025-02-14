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
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        ListNode* current = head;
        ListNode* leading = head;

        while(n--) { 
            leading = leading->next;
        }

        if (leading == nullptr) {
            return head->next;
        }

        while (leading->next) {
            current = current->next;
            leading = leading->next;
        }

        // Current should now be pointing at nth element from the end
        current->next = current->next->next;
        return head; 
    }
};