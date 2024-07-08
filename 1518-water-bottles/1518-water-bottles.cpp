class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int totalbottles=0;
        int emptybottles=0;
        
        while(numBottles>0){
            totalbottles+=numBottles;
            emptybottles+=numBottles;
            
            numBottles=emptybottles/numExchange;
            emptybottles=emptybottles%numExchange;
        }
        return totalbottles;
    }
};