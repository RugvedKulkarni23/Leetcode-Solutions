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
    
    int getlength(ListNode*head){
        ListNode*temp = head;
        int length=0;
        while(temp!=NULL){
            length++;
            temp = temp->next;
        }
        return length;
        
    }
    ListNode* swapNodes(ListNode* head, int k) {
          ListNode*temp = head;
          ListNode*temp1 = head;
          int count=1;
          while(count<k){
              temp=temp->next;
              count++;
          }
        int len = getlength(head);
        int count1=1;
        while(count1<(len-k+1)){
            temp1=temp1->next;
            count1++;
        }
        swap(temp->val,temp1->val);
              return head;
        
    }
};