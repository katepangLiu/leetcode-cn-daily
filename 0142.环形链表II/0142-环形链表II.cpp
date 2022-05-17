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
    ListNode *detectCycle(ListNode *head) {
        unordered_set<ListNode*> memo;
        ListNode* pNode = head;

        while( pNode ) {
            if( memo.find(pNode) != memo.end() ) {
                return pNode;
            }
            memo.insert(pNode);
            pNode = pNode->next;
        }
        return NULL;
    }
};