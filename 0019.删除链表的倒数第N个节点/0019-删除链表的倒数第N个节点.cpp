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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        
        ListNode tmphead(0);
        tmphead.next = head;

        ListNode* slow = &tmphead ;
        ListNode* fast = &tmphead ;

        for(int i =0; i<=n ;i++){
            fast= fast->next;
        }

        while(fast){
            slow = slow->next;
            fast = fast->next;
        }

        slow->next = slow->next->next;

        return tmphead.next;

    }
};