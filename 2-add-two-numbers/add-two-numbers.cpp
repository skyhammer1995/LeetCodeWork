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
        if (!l1 && !l2 && m_carry == 0) {
            return nullptr;
        }

        int sum = m_carry;
        if (l1) {
            sum += l1->val;
        }
        if (l2) {
            sum += l2->val;
        }

        m_carry = sum/k_ten;
        ListNode* lSolution = new ListNode(sum % k_ten);

        if (l1 || l2) {
            lSolution->next = addTwoNumbers(l1 ? l1->next : nullptr, l2 ? l2->next : nullptr);
        }

        return lSolution;
    }
private: 
    int m_carry = 0;
    static const int k_ten = 10;
};