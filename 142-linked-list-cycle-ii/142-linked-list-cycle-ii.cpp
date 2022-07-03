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
        
        
    }
};