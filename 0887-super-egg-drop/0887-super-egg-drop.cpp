// class Solution {
// public:
//     int superEggDrop(int k, int n) {
//         vector<vector<int>> dp(k+1,vector<int>(n+1,0));
//         //base cases
//         for(int j=0;j<=n;j++){
//             dp[1][j]=j;
//         }
//         for(int i=2;i<=k;i++){
//             for(int j=1;j<=n;j++){
//                 int low=1,high=j,result=j;
//                 while(low<=high){
//                     int mid=low+(high-low)/2;
//                     int breakCase=dp[i-1][mid-1];
//                     int notbreakCase=dp[i][j-mid];
//                     int worstCase=max(breakCase,notbreakCase)+1;
                    
//                     if(breakCase>notbreakCase){
//                         high=mid-1;
//                     }else{
//                         high=mid+1;
//                     }
                
//                 result=min(result,worstCase);
                
//             }
//             dp[i][j]=result;
//             }
//         }
//         return dp[k][n];
//     }
// };

class Solution {
public:
    int superEggDrop(int k, int n) {
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
        
        // Base case: with 1 egg, we need j attempts for j floors
        for (int j = 1; j <= n; ++j) {
            dp[1][j] = j;
        }
        
        // Fill the dp table
        for (int i = 2; i <= k; ++i) {
            for (int j = 1; j <= n; ++j) {
                int low = 1, high = j, result = j;
                while (low <= high) {
                    int mid = low + (high - low) / 2;
                    int breakCase = dp[i-1][mid-1];
                    int notBreakCase = dp[i][j-mid];
                    int worstCase = max(breakCase, notBreakCase) + 1;
                    
                    if (breakCase > notBreakCase) {
                        high = mid - 1;
                    } else {
                        low = mid + 1;
                    }
                    
                    result = min(result, worstCase);
                }
                dp[i][j] = result;
            }
        }
        
        return dp[k][n];
    }
};
