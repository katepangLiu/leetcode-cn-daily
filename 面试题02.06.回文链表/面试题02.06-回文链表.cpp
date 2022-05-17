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
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        vector<int> vec;
        int n = 0;
        int i = 0;

        while( head ) {
            st.push(head->val);
            vec.push_back(head->val);
            head = head->next;
            n++;
        }

        while( !st.empty() ) {
            if( vec[i] != st.top() ) {
                return false;
            }

            st.pop();
            i++;
        }

        return true;
    }
};