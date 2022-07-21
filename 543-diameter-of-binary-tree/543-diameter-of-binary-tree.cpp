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
    
    int height(TreeNode* root) {
        
        if(!root){
            return 0;
        }

        
        return 1 + max(height(root->left) , height(root->right));
        
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        
        if(!root){
            return 0;
        }
        
        int l_t_d = diameterOfBinaryTree(root->left);
        int r_t_d = diameterOfBinaryTree(root->right);
        
        int dia_root = height(root->left) + height(root->right);
        
        return max(dia_root, max(l_t_d, r_t_d));
        
    }
};