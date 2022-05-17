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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        
        ListNode tmphead(0);
        tmphead.next = head;
        ListNode* cur = &tmphead;
        ListNode* mPre = NULL;
        ListNode* pre = NULL;
        ListNode* next = NULL;

        for( int i=0 ;i<n+1; i++ ){
            if( i<m ){
                mPre = pre = cur;
                cur = cur->next;
            }else{
                next = cur->next;
                cur->next =pre;
                pre =cur;
                cur = next;
            }
        }

        mPre->next->next = cur;
        mPre->next = pre;

        return tmphead.next;
    }
};