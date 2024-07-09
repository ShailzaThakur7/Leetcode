// class Solution {
// public:
//     double averageWaitingTime(vector<vector<int>>& customers) {
//         int currentTime=0;
//         int longTime=0;
        
//         for(int i=0;i<customers.size();i++){
//             int arrivalTime=customers[i][0];
//             int serviceTime=customers[i][1];
            
//             if(currentTime<arrivalTime){
//                 currentTime=arrivalTime;
//             }
            
//             longTime+=(currentTime+serviceTime-arrivalTime);
            
//             currentTime+=serviceTime;
//         }
        
//         return static_cast<double>(longTime)/customers.size();
        
                
//     }
// };

class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int currentTime = 0;
        long long totalWaitingTime = 0;

        for (int i = 0; i < customers.size(); ++i) {
            int arrivalTime = customers[i][0];
            int serviceTime = customers[i][1];

            // If the cook is idle until the customer arrives
            if (currentTime < arrivalTime) {
                currentTime = arrivalTime;
            }

            // Calculate the waiting time for the current customer
            totalWaitingTime += (currentTime + serviceTime - arrivalTime);

            // Update the current time after serving the current customer
            currentTime += serviceTime;
        }

        // Return the average waiting time
        return static_cast<double>(totalWaitingTime) / customers.size();
    }
};
