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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
     ListNode* temp=head;
     int k=0;
     while(temp!=nullptr){
        k++;
        temp=temp->next;
     }
     if(k==1){
        if(n==0) return head;
        else return nullptr;
     }
     int x=k-n-1;
     if(x<0)return head->next;
     temp=head;
     while(x>0){
        temp=temp->next;
        x--;
     }
     temp->next=temp->next->next;
     return head;
    }
};