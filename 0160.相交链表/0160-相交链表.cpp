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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        stack<ListNode* > stackA;
        stack<ListNode* > stackB;

        ListNode* ptrA = headA;
        ListNode* ptrB = headB;

        while( ptrA ){
            stackA.push(ptrA);
            ptrA = ptrA->next;
        }

        while( ptrB ){
            stackB.push(ptrB);
            ptrB = ptrB->next;
        }

        while( !stackA.empty() && ! stackB.empty() ){
            if( stackA.top() != stackB.top() ){
                break;
            }

            ptrA = stackA.top();
            ptrB = stackB.top();
            stackA.pop();
            stackB.pop();
        }

        if( ptrA == ptrB ){
            return ptrA;
        }

        return NULL;
    }
};