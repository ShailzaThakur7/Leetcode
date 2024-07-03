class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n=nums.size();
        int left=0;
        int min_length=INT_MAX;
        int sum=0;
        
        for(int i=0;i<n;i++){
            sum+=nums[i];
            
            while(sum>=target){
                min_length=min(min_length,i-left+1);
                sum-=nums[left];
                ++left;
            }
        }
        return min_length == INT_MAX ? 0 : min_length;
        
    }
};