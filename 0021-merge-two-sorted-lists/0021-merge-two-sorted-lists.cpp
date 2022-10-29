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
    
    
    ListNode* solve(ListNode* list1, ListNode* list2){
        //If only one element is present in linked list
        if(list1->next==NULL){
             list1->next = list2;
            return list1;
        }
        ListNode*current1 = list1;
        ListNode*next1 = current1->next;
        ListNode*current2 = list2;
        ListNode*next2 = current2->next;
        while(next1!=NULL && current2!=NULL){
             if((current2->val>=current1->val) && (current2->val<=next1->val)){
                  current1->next = current2;
                  next2 = current2->next;
                  current2->next = next1;
                  current1 = current2;
                  current2 = next2;
             }
            else{
                 current1 = next1;
                 next1 = next1->next;
                 if(next1==NULL){
                      current1->next = current2;
                      return list1;
                 }
               
                 
            }
        }
        return list1;
        
        
        
    }
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
          if(list1==NULL){
              return list2;
          }
          if(list2==NULL){
              return list1;
          }
        if(list1->val<=list2->val){
            return solve(list1,list2);
             
        }
        else{
           return  solve(list2,list1);
        }
        
    }
};