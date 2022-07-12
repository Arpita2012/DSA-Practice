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
    ListNode* removeElements(ListNode* head, int val) {
        
        if(!head){
            return head;
        }
        
        while(head && head->val == val){
                ListNode* T = head;
                head=head->next;

                delete T;
                T=NULL;
            
        }
        
        ListNode* ans=head;
        if(!ans){
            return ans;
        }
        
        ListNode* prev =head;
        head=head->next;
        while(head){

            if(head->val == val){
                ListNode* T = head;
                
                prev->next = T->next;
                
                delete T;
                T=NULL;
                head =prev->next;
            }else{
                prev=prev->next;
                head=head->next;
            }
            
            
            
        }
        return ans;
        
        
    }
};