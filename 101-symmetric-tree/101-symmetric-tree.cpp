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
    
    
     bool helper(TreeNode* root1, TreeNode* root2)
 {
    if(!root1 and !root2) return true;
    else if(!root1 || !root2) return false;
    
    if(root1->val != root2->val) return false;
    return helper(root1->right, root2->left) && helper(root1->left, root2->right);
}
public:
bool isSymmetric(TreeNode* root) {
    return helper(root->left, root->right);
}
};