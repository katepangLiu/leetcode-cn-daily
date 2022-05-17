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
    bool hasCycle(ListNode *head) {
        if( !head ){
            return false;
        }

        ListNode* fast = head->next;
        ListNode* slow = head;
        int step = 0;

        while( fast != NULL ){
            if( fast == slow ){
                return true;
            }

            fast = fast->next;
            step++;

            if( step%2 ){
                slow = slow->next;
            }

        }

        return false;

    }
};