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
    void reorderList(ListNode* head) {
        if( !head || !head->next ) {
            return;
        }

        stack<ListNode*> st;
        ListNode* slow = head;
        ListNode* fast = head->next;
        int isOdd = 1;
        while( fast ) {
            fast = fast->next;
            if( !fast ) {
                isOdd = 0;
                break;
            }
            fast = fast->next;
            slow = slow->next;
        }

        cout << slow->val << ',' << isOdd << endl;
        
        ListNode* mid = slow;
        ListNode* ptr = mid->next;

        while( ptr ) {
            ListNode* next = ptr->next;
            ptr->next = nullptr;

            st.push(ptr);
            ptr = next;
        }

        ptr = head;
        while ( ptr != mid ) {
            cout << ptr->val << endl;
            ListNode* next = ptr->next;
            ptr->next = st.top();
            st.pop();
            ptr->next->next = next;
            cout << ptr->val << ',' << ptr->next->val << ','  << ptr->next->next->val  << endl;
            ptr = next;
        } 
        if( isOdd ) {
            mid->next = nullptr;
        } 

        return ;
    }
};