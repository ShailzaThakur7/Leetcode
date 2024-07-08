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
    int sumNumbers(TreeNode* root) {
        
        return dfs(root,0);
        
    }
private:
    int dfs(TreeNode* node,int currentSum){
        if(node==NULL){
            return 0;
        }
        currentSum=currentSum*10 + node->val;
        
        if(node->left==NULL && node->right==NULL){
            return currentSum;
        }
        return dfs(node->left,currentSum)+dfs(node->right,currentSum);
    }
};