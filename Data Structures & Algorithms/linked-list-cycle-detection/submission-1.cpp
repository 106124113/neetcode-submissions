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
    bool hasCycle(ListNode* head) {
        set<ListNode*>st;
        ListNode* temp=head;
        while(temp!=nullptr){
          if(st.count(temp)) return true;
          st.insert(temp);
          temp=temp->next;
        }
        return false;
    }
};
