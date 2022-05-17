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
    ListNode* oddEvenList(ListNode* head) {
        if( !head || !head->next ) {
            return head;
        }

        ListNode evenHead(0);
        ListNode oddHead(0);
        ListNode* even = &evenHead;
        ListNode* odd = &oddHead;

        ListNode* ptr = head;
        int idx = 1;

        while( ptr ) {
            if( idx %2 ) {
                even->next = ptr;
                even = even->next;
            } else {
                odd->next = ptr;
                odd = odd->next;
            }
            ptr = ptr->next;
            idx++;
        }

        even->next = oddHead.next;
        odd->next = nullptr;
        return evenHead.next;
    }
};