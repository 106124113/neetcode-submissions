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

    ListNode* reverseList(ListNode* firstNode, ListNode* lastNode,ListNode* prev = nullptr) {

        ListNode* curr = firstNode;
        ListNode* next;
        ListNode* stopNode = lastNode->next;

        while(curr != stopNode) {

            next = curr->next;
            curr->next = prev;

            prev = curr;
            curr = next;
        }

        return prev;
    }

public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        
        ListNode* tmpNode = head;
        ListNode* firstNode = head;
        ListNode* lastNode = nullptr;
        ListNode* prevNode = nullptr;
        
        int tmpK = k;

        while(tmpNode != nullptr) {

            tmpK--;

            if(tmpK == 0) {

                lastNode = tmpNode;
                ListNode* lastNodeNext = lastNode->next;

                if(firstNode == head) {
                    reverseList(firstNode, lastNode);
                    head = lastNode;
                }
                else {
                    reverseList(firstNode, lastNode);
                }

                firstNode->next = lastNodeNext;

                if(prevNode != nullptr) {
                    prevNode->next = lastNode;
                }

                tmpK = k;
                tmpNode = firstNode;
                prevNode = firstNode;
                firstNode = lastNodeNext;
            }

            tmpNode = tmpNode->next;
        }

        return head;

    }
};