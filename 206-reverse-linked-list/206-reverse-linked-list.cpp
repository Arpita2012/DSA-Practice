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
    ListNode* reverseList(ListNode* head) {
        ListNode* prevptr=nullptr , *nextptr = nullptr;
        
        if(head==NULL || head->next ==NULL ){
            return head;
        }
        
        
        
        while(head){
           
            nextptr = head->next;
            head->next = prevptr;
            
            prevptr = head;
            head = nextptr;
            
            
            
            
        }
        
        return prevptr;
        
    }
};