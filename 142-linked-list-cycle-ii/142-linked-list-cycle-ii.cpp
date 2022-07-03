/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
     /* M1   Space Complexity - O(n)
      ListNode *T=head;
        
       map <ListNode*, ListNode*> m;
        
       while(T){
           
           if(m.find(T)==m.end()){
               m[T]=T->next;
           }else{
               break;
           }
           T=T->next;
           
       }
        
       return T; 
      */
        
        /* M2   Space Complexity - O(1)*/ 
        
        if((!head) || (!head->next)){
            return NULL;
        }
        
         ListNode *fast=head;
         ListNode *slow=head;
        
        ListNode* prev =head;
        bool flag = false;
        while(fast&& fast->next ){
            fast=fast->next->next;
            slow=slow->next;
            
            if(fast==slow){  //this will happen at any node present within cycle
                flag = true;
                break;
            } 
        }
        
        //to find out the exact which node tail connects to...
        
        ListNode * detectNodePtr = head;
        
        if(flag){
            
            while(detectNodePtr!=fast){
                fast=fast->next;
                detectNodePtr=detectNodePtr->next;
            }
            
            return detectNodePtr;
               
        }
        
        
        return NULL;
        
       
        
        
        
        
    }
};