class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> ds;
        subset(nums,ds,ans);
        return ans;
        
    }
    private:
    void subset(vector<int>& nums, vector<int> &ds,vector<vector<int>> &ans){
        if(ds.size()==nums.size()){
            ans.push_back(ds);
            return;
        }
        
        for(int i=0;i<nums.size();i++){
            if(find(ds.begin(),ds.end(),nums[i])!=ds.end()){
                continue;
            }
               ds.push_back(nums[i]);
               subset(nums,ds,ans);
               ds.pop_back();
            
        }
    }
};