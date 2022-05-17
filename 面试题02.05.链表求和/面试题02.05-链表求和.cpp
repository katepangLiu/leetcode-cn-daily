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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int val1 = 0;
        int val2 = 0;
        int val = 0;
        ListNode tmphead(0);
        ListNode* l = &tmphead;

        while( l1 || l2 || val ) {
            val1 = l1 ? l1->val : 0;
            val2 = l2 ? l2->val : 0;
            l1 = l1 ? l1->next : NULL;
            l2 = l2 ? l2->next : NULL;

            val += val1 + val2;
            ListNode* node = new ListNode(val%10);
            val = val/10;
            l->next = node;
            l = l->next;
        }

        return tmphead.next;
    }
};