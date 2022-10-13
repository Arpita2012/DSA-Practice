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
    void deleteNode(ListNode* node) {
        
        ListNode * temp = node;
        
        
        ListNode * temp_next = node->next;
        
        temp->val = temp_next->val;
        
        temp->next = temp_next->next;
        
        delete temp_next;
        
        
        
        
    }
};