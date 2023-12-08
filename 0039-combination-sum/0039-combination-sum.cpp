class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>> ans;
        vector<int> ds;
        backtrack(candidates,target,0,ds,ans);
        return ans;
        
    }

private:
    void backtrack(vector<int>& candidates,int target,int ind,vector<int> &ds,vector<vector<int>> &ans){
        if(target==0){
            ans.push_back(ds);
            return;
        }
        
        for(int i=ind;i<candidates.size();i++){
            if(candidates[i]<=target){
                ds.push_back(candidates[i]);
                backtrack(candidates,target-candidates[i],i,ds,ans);
                ds.pop_back();
            }
            
        }
    }
};