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
    string getDirections(TreeNode* root, int startValue, int destValue) {        
        vector<TreeNode*> start; //storing the LCA of start
        vector<TreeNode*> dest; //storing the LCA of dest
        
        findPath(root,startValue,start);
        findPath(root,destValue,dest);
        
        int i=0;
        while(i<start.size() && i<dest.size() && start[i]==dest[i]){
            i++;
        }
        
        string directions;
        for(int j=i;j<start.size();j++){
            directions+='U';
        }
        
        for(int j=i;j<dest.size();j++){
            if(dest[j-1]->left==dest[j]){
                directions+='L';                
            }else{
                directions+='R';
            }
            
        }
        return directions;
        
    }
private:
    bool findPath(TreeNode* root,int value,vector<TreeNode*>& path){
        if(root==NULL){
            return false;
        }
        
        path.push_back(root);
        if(root->val==value){
            return true;
        }
        
        if(findPath(root->left,value,path) || findPath(root->right,value,path)){
            return true;
        }
        path.pop_back();
        return false;
        
    }
};