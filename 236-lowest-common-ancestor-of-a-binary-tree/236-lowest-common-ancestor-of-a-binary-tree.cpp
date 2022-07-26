/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if(!root)
            return root;
        
        if(p==root || q==root){
            return root;
        }
        
        TreeNode* leftC=NULL, *rightC=NULL;
        
        if(root->left)
             leftC = lowestCommonAncestor(root->left,p,q);
        
        if(root->right)
             rightC = lowestCommonAncestor(root->right,p,q);
        
        if(leftC&& rightC){
            return root;
        }
        
        return leftC? leftC:rightC;
        
    }
};