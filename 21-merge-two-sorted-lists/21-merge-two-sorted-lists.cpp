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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
         ListNode* FL = nullptr;  ListNode* track =NULL;
        
        ListNode *temp =NULL ;
        while (l1 && l2){
            if(l1->val < l2->val){
                temp = new ListNode(l1->val);
                l1=l1->next;
            }else{
                temp = new ListNode(l2->val);   
                 l2=l2->next;
            }
            
            if(FL ==NULL){
                FL = temp;
                track=FL;
            }
            else{
                track ->next = temp;
                track = track->next;
            }  
            
            
            
            
        }
         while (l1 ){
           
            temp = new ListNode(l1->val);
              l1=l1->next;
           
            if(FL ==NULL){
                FL = temp;
                track=FL;
            }
            else{
                track ->next = temp;
                track = track->next;
            }  
            
        }
        
         while (l2){
           
           temp = new ListNode(l2->val);
              l2=l2->next;
           
            if(FL ==NULL){
                FL = temp;
                track=FL;
            }
            else{
                track ->next = temp;
                track = track->next;
            }  
            
            
            
        }
        
        return FL;
        
        
    }
};