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

/*
class Solution {
    ListNode * reverse(ListNode* node){
        if (node == NULL)
            return NULL;
        if (node->next == NULL) {
            
            return node;
        }
        ListNode* node1 = reverse(node->next);
        node1->next = node;
        node->next = NULL;
        return node;
        
    }
    
public:
    bool isPalindrome(ListNode* head) {
        int cnt = 0;
        ListNode* t = head;
        
        while(t){
            t=t->next;
            cnt++;
        }
        
        int i=0; 
        
        int rev_strt_ind = cnt%2==0? (cnt/2): ((cnt/2)+1) ;
        
        ListNode *rev = head;
        while(i<=rev_strt_ind){
            rev=rev->next;
            i++;
            
            if(i<rev_strt_ind && rev==NULL){
                
            }
        }
        
        ListNode* midNode = reverse(rev);
        
        bool flag = false;
        while(midNode!=NULL){
            
            if(head->val == midNode->val){
                flag=true;
            }else{
                flag=false;
                break;
            }
            midNode = midNode ->next;
            
        }
        
        return flag;
    }
};*/

class Solution
{
    public:
        ListNode* rev(ListNode *head)
        {
            ListNode *temp1 = head, *temp2 = head->next, *prev = nullptr;
            while (temp2 != nullptr)
            {
                temp1->next = prev;
                prev = temp1;
                temp1 = temp2;
                temp2 = temp2->next;
            }
            temp1->next = prev;
            return temp1;
        }
    bool isPalindrome(ListNode *head)
    {
        if (head->next == nullptr)
            return true;
        ListNode *slow = head, *fast = head->next;
        while (fast != nullptr && fast->next != nullptr)
            slow = slow->next, fast = fast->next->next;
        ListNode *newHead = slow->next;
        slow->next = nullptr;
        newHead = rev(newHead);
        while (newHead != nullptr)
        {
            if (head->val != newHead->val)
                return false;
            head = head->next, newHead = newHead->next;
        }
        return true;
    }
};