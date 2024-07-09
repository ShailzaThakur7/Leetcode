class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int currentTime=0;
        long long longTime=0;
        
        for(int i=0;i<customers.size();i++){
            int arrivalTime=customers[i][0];
            int serviceTime=customers[i][1];
            
            if(currentTime<arrivalTime){
                currentTime=arrivalTime;
            }
            
            longTime+=(currentTime+serviceTime-arrivalTime);
            
            currentTime+=serviceTime;
        }
        
        return static_cast<double>(longTime)/customers.size();
        
                
    }
};