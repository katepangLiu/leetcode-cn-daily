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
    ListNode* swapPairs(ListNode* head) {
        if( !head || !head->next ) {
            return head;
        }

        ListNode* slow = head ;
        ListNode* fast = head->next ;
        ListNode tmphead(0);
        ListNode* prev = &tmphead;

        while( fast ) {
            prev->next = fast;
            slow->next = fast->next;
            fast->next = slow;
            prev = slow;

            slow = prev->next;
            fast = slow;
            if( fast ) {
                fast = fast->next;
            }
        }

        return tmphead.next;
    }
};