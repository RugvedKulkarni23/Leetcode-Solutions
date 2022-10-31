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
    ListNode* swapNodes(ListNode* head, int k) {
          ListNode*temp = head;
          int count=1;
          while(count<k){
              temp = temp->next;
              count++;
          }
        ListNode*kth = temp;
        temp = temp->next;
        ListNode*temp1=head;
        while(temp!=NULL){
            temp=temp->next;
            temp1=temp1->next;
        }
        swap(temp1->val,kth->val);
        return head;
        
    }
};