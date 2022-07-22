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
    ListNode* partition(ListNode* head, int x) {
        ListNode* l1_head =NULL;
        ListNode* l2_head =NULL;
        ListNode* l1_tail =NULL;
        ListNode* l2_tail =NULL;
        
        while(head){
            if(head->val < x){
                
                if(!l1_head){
                    l1_head=new ListNode(head->val);
                    l1_tail=l1_head;
                }else{
                    ListNode* t = new ListNode(head->val);
                    l1_tail->next = t;
                    l1_tail =t;
                }
                
            }else{
                
                 if(!l2_head){
                    l2_head=new ListNode(head->val);
                    l2_tail=l2_head;
                }else{
                    ListNode* t = new ListNode(head->val);
                    l2_tail->next = t;
                    l2_tail =t;
                }
                
            }
            head=head->next;
        }
        
        if(l1_tail){
            l1_tail->next = l2_head;
            return l1_head;
        }else{
            return l2_head;
        }
        
        
    }
};