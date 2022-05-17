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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode tmphead(0);
        ListNode* prev = &tmphead;
        prev->next = head;
        ListNode* tail = prev;

        while( head ) {
            for( int i=0; i<k; i++ ) {
                tail = tail->next;
                if( !tail ) {
                    return tmphead.next;
                }
            }

            tie(head, tail) = reverse(head, tail);
            prev->next = head;
            prev = tail;
            head = tail->next;
        }

        return tmphead.next;

    }

    pair<ListNode*, ListNode*> reverse(ListNode* head, ListNode* tail) {
        ListNode* prev = tail->next;
        ListNode* cur = head;
        ListNode* next = NULL;
        while( prev != tail ) {
            next = cur->next;
            cur->next = prev;
            prev =cur;
            cur = next;
        }

        return {tail, head};
    }

};