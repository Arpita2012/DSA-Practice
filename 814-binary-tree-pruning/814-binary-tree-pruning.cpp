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


bool checkOneContained(TreeNode * node){
    
    if (!node){
        return false;
    }
    
    bool leftSubtree = checkOneContained(node->left);
    bool rightSubtree = checkOneContained(node->right);
    
    if(!leftSubtree){
        node->left = NULL;
    }
    if(!rightSubtree){
        node->right = NULL;
    }
    
    
    return node->val == 1 || leftSubtree || rightSubtree;
    
    
    
}

class Solution {
public:
    TreeNode* pruneTree(TreeNode* root) {
        if (checkOneContained(root)){
            return root;
        }else {
            return NULL;
        }
    }
};