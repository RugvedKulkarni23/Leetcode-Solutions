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
private:
    
    ListNode* reverse(ListNode* head){
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
     void insertattail(ListNode*&head,ListNode*&tail, int digit){
            ListNode*temp = new ListNode(digit);
            if(head==NULL){
                 head = temp;
                 tail = temp;
                 return;
            }
         else{
         tail->next = temp;
         tail = temp;
         }
     }
    ListNode* add(ListNode* l1, ListNode* l2){
          int carry =0;
          ListNode*answerhead = NULL;
          ListNode*answertail = NULL;
          while(l1!=NULL || l2!=NULL || carry!=0){
               int val1 = 0;
               if(l1!=NULL){
                    val1 = l1->val;
               }
               int val2 = 0;
               if(l2!=NULL){
                   val2 = l2->val;
               }
               int sum = carry+val1+val2;
               int digit = sum%10;
               //create node and add in answer linked list
               insertattail(answerhead,answertail,digit);
               carry = sum/10;
               if(l1!=NULL){
               l1 = l1->next;}
               if(l2!=NULL){
               l2 = l2->next;}
          }
        
        return answerhead;
        
    }
    public:
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
         //Reverse input  Linked List   Step 1 
         
          l1 = reverse(l1);
          l2 = reverse(l2);
          // step 2 addition of two linked lists 
          ListNode*answer = add(l1,l2);
          //step 3 reversal of answer 
         answer = reverse(answer);
         return answer;
    }
};