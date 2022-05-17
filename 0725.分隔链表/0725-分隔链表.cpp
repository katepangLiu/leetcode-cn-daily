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
    ListNode* partition(ListNode* head, int x) {
        ListNode tmpSmailHead(0);
        ListNode tmpBigHead(0);
        ListNode* pSmail = &tmpSmailHead;
        ListNode* pBig = &tmpBigHead;

        ListNode* pNode = head;
        while(pNode) {
            //cout << pNode->val;
            if( pNode->val < x) {
                //cout << " smail" << endl;
                pSmail->next = pNode;
                pSmail = pSmail->next;
            } else {
                //cout << " big" << endl;
                pBig->next = pNode;
                pBig = pBig->next;
            }
            pNode = pNode->next;
        }

        pSmail->next = tmpBigHead.next;
        pBig->next = NULL;
        return tmpSmailHead.next;
    }
};