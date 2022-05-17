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
        ListNode tmphead(0);
        ListNode* p = &tmphead;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        int buf = 0;

        while( p1 || p2 || buf ) {
            int val1 = p1 ? p1->val : 0;
            int val2 = p2 ? p2->val : 0;
        
            buf += val1 + val2;
            p->next = new ListNode( buf%10 );
            buf = buf/10;

            p1 = p1 ? p1->next : nullptr ;
            p2 = p2 ? p2->next : nullptr ;
            p = p->next;
        }

        return tmphead.next;

    }
};