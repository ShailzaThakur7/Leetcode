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
    void traversal(TreeNode* node,vector<int> &x){
        //no node case
        if(!node){
            return;
        }
        
        //no left right node 
        if(!node->left && !node->right){
            x.push_back(node->val);
            return ;
        }
        
        //left traversal
        if(node->left){
            traversal(node->left,x);
            
        }
        x.push_back(node->val);
        
        //right traversal
        if(node->right){
            traversal(node->right,x);
            
        }
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> x;
        traversal(root,x);
        return x;
        
    }
};