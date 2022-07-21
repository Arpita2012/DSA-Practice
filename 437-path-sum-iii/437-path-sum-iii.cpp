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
    void solve(TreeNode *root,int target,vector<int>&ans,int& count){
        if(root==NULL){
            return;
        }
        ans.push_back(root->val);
        solve(root->left,target,ans,count);
        solve(root->right,target,ans,count);
        long sum=0;
        for(int i=ans.size()-1;i>=0;i--){
            sum+=ans[i];
            if(sum==target){
                count++;
                
            }
        }
        ans.pop_back();
    }
    int pathSum(TreeNode* root, int target) {
        int count=0;
        vector<int>ans;
        solve(root,target,ans,count);
        return count;
    }
};