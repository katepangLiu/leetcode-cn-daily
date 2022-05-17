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
    ListNode* reverseList(ListNode* head) {
        if( !head ) {
            return NULL;
        }

        ListNode* prev = NULL;
        ListNode* cur = head;
        ListNode* next = cur->next;

        while( next ) {
            cur->next = prev;
            prev = cur;
            cur = next;
            next = next->next;
        }

        cur->next = prev;

        return cur;
    }
};