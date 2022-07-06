/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

// P  - > node print
//   -all childrn

class Solution {
public:
    vector<int> preorder(Node* root) {
        
        vector <int> res;
        
        stack<Node* > S ;
        if(!root){
            return res;
        }
        S.push(root);
        
        while(!S.empty()){
            
            Node* temp = S.top();
            
            res.push_back(temp->val);
            
            S.pop();
            
            //getting children of temp
            
            vector<Node*> childrenTemp = temp->children;
            
            for(int i= childrenTemp.size()-1; i>=0; i--){
                S.push(childrenTemp[i]);
            }
            
            
        }
        
        return res;
        
        
    }
};