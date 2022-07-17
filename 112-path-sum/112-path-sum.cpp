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
public: bool check(TreeNode* root, int target,int sum,bool &ans){
    
    if(ans){
        return true;
    }
    if((!root->left && !root->right) && (sum==target))
    {
        ans=true;
        return ans;
    }
    if(root->left)
    check(root->left,target,root->left->val +sum,ans);
    if(root->right)
    check(root->right,target,root->right->val+sum, ans);
    return ans;
}
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)
            return false;
        bool ans=false;
        return (check(root,targetSum,root->val,ans));
        
        
    }
};