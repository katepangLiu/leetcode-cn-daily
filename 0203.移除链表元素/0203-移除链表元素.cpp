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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode tmphead(0);
        ListNode* prev = &tmphead;

        while( head ) {
            if( val != head->val ) {
                prev->next = head;
                prev = prev->next;
            }
            head = head->next;
        }
        prev->next = NULL;

        return tmphead.next;

    }
};