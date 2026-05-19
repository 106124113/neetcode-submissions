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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
   ListNode* temp1=l1,*temp2=l2;
   int carry=0;
   ListNode* head=nullptr,*temp=nullptr;
   while(temp1 && temp2){
    ListNode* newnode=new ListNode(temp1->val+temp2->val+carry);
    if((temp1->val+temp2->val+carry)/10==1) {
        newnode->val=(temp1->val+temp2->val+carry)%10;
        carry=1;
    }
    else{
        carry=0;
    }
     if(!head) {
        head=newnode;
        temp=head;
     }
     else{
temp->next=newnode;
 temp=temp->next;
     }
     temp1=temp1->next;
     temp2=temp2->next;
    }
  while(temp1){
      temp->next=new ListNode(temp1->val+carry);
      if(temp->next->val/10==1) {
        temp->next->val=temp->next->val%10;
        carry=1;
      }
      else{
        carry=0;
    }
      temp=temp->next;
      temp1=temp1->next;
  }
   while(temp2){
      temp->next=new ListNode(temp2->val+carry);
      if(temp->next->val/10==1) {
        temp->next->val=temp->next->val%10;
        carry=1;
      }
      else{
        carry=0;
    }
      temp=temp->next;
      temp2=temp2->next;
  }
  if(carry==1) temp->next=new ListNode(1);
  return head;
    }
};