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
    
    void reverse(ListNode*&head,ListNode*&current,ListNode*&previous){
            //Base Case
            if(current == NULL){
                head=previous;
                return;
            }
            ListNode*forward = current->next;
            reverse(head,forward,current);
            current->next=previous;
    }
    ListNode* reverseList(ListNode* head) {
          ListNode*current = head;
          ListNode*previous = NULL;
          reverse(head,current,previous);
          return head;
    }
};