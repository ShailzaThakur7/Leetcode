class Solution {
public:
    
    bool dfs(int node,int col,vector<int> &color,vector<vector<int>>& graph){
        color[node]=col;
        for(auto i:graph[node]){
            if(color[i]==-1){
            if(!dfs(i,1-col,color,graph)){
                return false;
            }
            }else if(color[i]==color[node]){
                return false;
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<int> color(n,-1);
        // vector<int> vis(n+1,0);
        for(int i=0;i<graph.size();i++){
            if(color[i]==-1){
                if(!dfs(i,0,color,graph)){
                    return false;
                }
            }
            
        }
        return true;
        
    }
};