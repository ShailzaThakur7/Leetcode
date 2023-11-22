class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
         vector<vector<int>> result;
//         sort
        sort(nums.begin(),nums.end());
        
//         duplicate
        for(int i=0;i<nums.size()-2;i++){ //we need three elements so nums-2
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            
        
//         sum of three numbers
        int target=-nums[i]; //since sum of three numbers is 0 we will find sum of two
        int left=i+1;
        int right=nums.size()-1;
        
        while(left<right){
            int sum=nums[left]+nums[right];
            if(sum==target){
                result.push_back({nums[i],nums[left],nums[right]});
            
            //duplicate
            while(left<right && nums[left]==nums[left+1]){
                left++;
            }
            while(left<right && nums[right]==nums[right-1]){
                right--;
            }
            left++;
            right--;
            }
            
        else if(sum<target){
            left++;
        }
        else{
            right--;
        }
        
        
    }
        }
        return result;
    }
};