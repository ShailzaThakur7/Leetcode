class Solution {
public:
    
    void dfs(int node,vector<bool> &vis,vector<vector<int>>& isConnected){
        vis[node]=true;
        for(int i=0;i<isConnected.size();i++){
            if(!vis[i] && isConnected[node][i]==1){
                dfs(i,vis,isConnected);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n=isConnected.size();
        int count=0;
        vector<bool> vis(n+1,0);
        
        for(int i=0;i<n;i++){
            if(!vis[i]){
                count++;
                dfs(i,vis,isConnected);
            }
        }
        return count;
        
    }
};