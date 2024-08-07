class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        int maxlength=0;
        vector<int> dp(n,1);
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i],dp[j]+1);
                }
            }
            maxlength=max(maxlength,dp[i]);
        }
        return maxlength;
//         int n=nums.size();
//         vector<int> dp(n,1);
//         int maxlength=1;
        
//         for(int i=0;i<n;i++){
//             for(int j=0;j<i;j++){
//                   if(nums[i]>nums[j]){
//                       dp[i]=max(dp[i],dp[j]+1);
//                   }              
//             }
//             maxlength=max(maxlength,dp[i]);
//         }
//         return maxlength;
        
    }
};