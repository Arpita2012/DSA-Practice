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
    
   /*void inorder(TreeNode* root,vector <int> &inn) {
        if(root){
            inorder(root->left,inn);
            inn.push_back(root->val);
            inorder(root->right,inn);
            
        }
    }
    
    bool isSymmetric(TreeNode* root) {
        vector <int> inn;
        inorder(root, inn);
        int n = inn.size();
        for(int i=0; i< n ; i++){
            cout<<inn[i]<<endl;
        }
        
        for(int i=0; i< n/2 ; i++){
            
            if(inn[i]!=inn[n-i-1]){
                return false;
            }
            
            
        }
        
        return true;
    }*/
    
    
     bool isSameTree(TreeNode* p, TreeNode* q) {
        
        if(!p and !q) 
            return true;
        else if(!p || !q) 
            return false;

        if(p->val != q->val) 
            return false;
        
        return isSameTree(p->left, q->right) && isSameTree(p->right, q->left);
        
    }
    
    public:
    bool isSymmetric(TreeNode* root) {
        return isSameTree(root->left, root->right);
    }
};