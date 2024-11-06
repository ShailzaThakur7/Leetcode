class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int count=0,fo=0;
        int n=grid.size();
        int m=grid[0].size();
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }else if(grid[i][j]==1){
                    fo++;
                }
            }
        }
        if(fo==0){
            return count;
        }
        if(q.empty()){
            return -1;
        }
        int dx[4]={0,1,-1,0};
        int dy[4]={1,0,0,-1};
        while(!q.empty() && fo>0){
            int size=q.size();
            for(int i=0;i<size;i++){
                int x=q.front().first;
                int y=q.front().second;
                q.pop();
                for(int i=0;i<4;i++){
                    int nx=x+dx[i],ny=y+dy[i];
                    if(nx>=0 && ny>=0 && ny<m && nx<n && grid[nx][ny]==1){
                        grid[nx][ny]=2;
                        q.push({nx,ny});
                        fo--;
                    }
                }
                
            }
            count++;
            
        }

        if(fo==0){
            return count;
        }
            return -1;
        
        
              
        
    }
};