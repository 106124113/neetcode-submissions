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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head=nullptr,*temp=nullptr,*temp1=list1,*temp2=list2;

        while(temp1!=nullptr && temp2!=nullptr){
          if(temp1->val==temp2->val){
            if(!head){
              head=new ListNode(temp1->val);
              temp1=temp1->next;
              temp=head;
            }
            else{
              temp->next=new ListNode(temp1->val);
              temp1=temp1->next;
              temp=temp->next;
            }
             temp->next=new ListNode(temp2->val);
              temp2=temp2->next;
              temp=temp->next;
          }
          else if(temp1->val<temp2->val){
              if(!head){
              head=new ListNode(temp1->val);
              temp1=temp1->next;
              temp=head;
            }
            else{
            temp->next=new ListNode(temp1->val);
            temp=temp->next;
            temp1=temp1->next;
            }
          }
          else{
              if(!head){
              head=new ListNode(temp2->val);
              temp2=temp2->next;
              temp=head;
            }
            else{
            temp->next=new ListNode(temp2->val);
            temp=temp->next;
            temp2=temp2->next;
            }
          }
        }
while(temp1!=nullptr){
  if(!head) return list1;
  temp->next=new ListNode(temp1->val);
            temp=temp->next;
            temp1=temp1->next;
}
while(temp2!=nullptr){
  if(!head) return list2;
    temp->next=new ListNode(temp2->val);
            temp=temp->next;
            temp2=temp2->next;
}
return head;
    }
};
