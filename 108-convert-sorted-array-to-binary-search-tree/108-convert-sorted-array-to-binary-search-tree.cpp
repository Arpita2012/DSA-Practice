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
    
    TreeNode* divide(vector<int>& nums, int f,int l){
        
        if(f>l){
            return NULL;
        }
        
        int m = f+ (l-f)/2;
        TreeNode* R = new TreeNode(nums[m]);
        
        R->left = divide(nums, f, m-1);

         R->right = divide(nums,  m+1,l);
        return R;
    }
    
    TreeNode* sortedArrayToBST(vector<int>& nums) {
     
        TreeNode* root=NULL;
        
        return divide(nums, 0, nums.size()-1);
        
        
        
    }
};