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
    ListNode* removeZeroSumSublists(ListNode* head) {
        ListNode* tmphead = new ListNode(0);
        tmphead->next = head;

        map<int, ListNode*> m;
        int sum = 0;
        ListNode* node = tmphead;
        while( node ) {
            sum += node->val;
            m[sum] = node;
            node = node->next;
        }

        sum = 0;
        node = tmphead;
        while( node ) {
            sum += node->val;
            node->next = m[sum]->next;
            node = node->next;
        }

        return tmphead->next;

    }
};