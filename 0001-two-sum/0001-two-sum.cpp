class Solution {
public:
//check
    vector<int> twoSum(vector<int>& nums, int target) {
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    // cout<<"["<<i<<","<<j<<"]"<<endl;
                    return {i,j};
                }
            }
        }
        return {};
        
    }
};
