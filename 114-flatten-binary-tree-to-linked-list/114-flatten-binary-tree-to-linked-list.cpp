/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) {
        if(!root){
            return;
        }
        
        stack<TreeNode*> S;
        
        
        S.push(root);
        while(!S.empty()){
            TreeNode* temp = S.top();
            cout<<temp->val<<" ";
            S.pop();
            
            if(temp->right){
                S.push(temp->right);
                
            }
            
            if(temp->left){
                S.push(temp->left);
                
            }
            
            temp->left=NULL;
            
            if(!S.empty()){
                temp->right = S.top();
            }else{
                temp->right=NULL;
            }
            
            
            
        }
        
        
    }
};