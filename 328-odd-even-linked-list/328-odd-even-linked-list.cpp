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
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;
        ListNode* firstEvenNode = head->next;
        ListNode* odd = head;
        ListNode* even = head->next;
        ListNode* it = head;
        int i = 1;
        while(it){
            ListNode* temp = it->next;
            if(i%2){
                odd->next = it;
                odd = it;
            }
            else if(even){
                even->next = it;
                even = it;
            }
            i++;
            it = temp;
        }
        if(even) even->next = NULL;
        odd->next = firstEvenNode;
        return head;
    }
};