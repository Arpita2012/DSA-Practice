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
        
        ListNode* new_head=NULL;
        ListNode* temp=NULL;
        int c=0;
        while(l1 && l2){
            int S = l1->val + l2->val + c;
            
            c = S/10;
            
            if(!new_head){
                new_head = new ListNode(S%10);
                temp=new_head;
            }else{
                temp->next=new ListNode(S%10);
                temp=temp->next;
            }
            
            l1=l1->next;
            l2=l2->next;
            
            
        }
        
        while(l1){
            int S = l1->val +  c;
            
             c = S/10;
            
            if(!new_head){
                new_head = new ListNode(S%10);
                temp=new_head;
            }else{
                temp->next=new ListNode(S%10);
                temp=temp->next;
            }
            l1=l1->next;
        }
         while(l2){
            int S = l2->val +  c;
            
            c = S/10;
            
            if(!new_head){
                new_head = new ListNode(S%10);
                temp=new_head;
            }else{
                temp->next=new ListNode(S%10);
                temp=temp->next;
            }
            l2=l2->next;
        }
        
        if(c){
            temp->next=new ListNode(c);
               
        }
        
        return new_head;
        
    }
};