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
    bool stop ;
    ListNode* left =NULL;
    void recurse( ListNode* right, int m, int n){
        
        
        if(n==1){
            return ;
        }
        
        right=right->next;
        
        if(m>1){
            left=left->next;
            //cout<<"ll "<<left<<endl;

        }
        recurse(right,m-1,n-1);
        
        if(right==left || right->next==left){
            stop=true;
        }
        
        if(!stop){
            
            //cout<<left->val <<" "<<right->val<<endl;
            int temp = left->val;
            left->val = right->val;
            right->val = temp;
            left=left->next;
        }
        
        
    }
   
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        stop=false;
        left=head;
        
        recurse(head,m,n);
        return head;
    }
};