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
    
    ListNode* findmiddle(ListNode*head){
        ListNode*slow = head;
        ListNode*fast = head->next;
        while(fast!=NULL  && fast->next!=NULL){
               fast = fast->next->next;
               slow = slow->next;
            
        }
        return slow;
    }
    ListNode* reverse(ListNode*head){
         ListNode*previous = NULL;
         ListNode*current = head;
         ListNode*forward = NULL;
         while(current!=NULL){
              forward = current->next;
              current->next = previous;
              previous = current;
              current = forward;
         }
        return previous;
    }
    bool isPalindrome(ListNode* head) {
        //For single element
        if(head->next==NULL){
            return true;
        }
        ListNode*middle = findmiddle(head);
        ListNode*temp = middle->next;
        middle->next = reverse(temp);
        ListNode*head1 = head;
        ListNode*head2 = middle->next;
        while(head2!=NULL){
            if(head1->val!=head2->val){
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        temp = middle->next;
        middle->next = reverse(temp);
        return true;
    }
};