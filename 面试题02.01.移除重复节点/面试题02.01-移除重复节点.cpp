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
    ListNode* removeDuplicateNodes(ListNode* head) {
        ListNode tmphead(0);
        ListNode* pNode = &tmphead;
        tmphead.next = head;
        unordered_set<int> memo;

        while( head ) {
            if( memo.find(head->val) != memo.end() ) {
                head = head->next;
                continue;
            }
            memo.insert(head->val);
            pNode->next = head;
            pNode = pNode->next;
            head = head->next;
        }

        pNode->next = NULL;
        return tmphead.next;
    }
};