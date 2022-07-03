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
    ListNode* middleNode(ListNode* head) {
        
        ListNode* T1=head , *T2=head;
        
        int cnt =0 ;
        while(T1){
            T1=T1->next;
            
            cnt++;
        }
        
        T1 =head;
        while(T2&&T2->next&&T2->next->next){
            T1=T1->next;
            T2=T2->next->next;
           
        }
        
        
        //cout<<cnt<<endl;
        
        return cnt%2?T1:T1->next;
        
        
    }
};