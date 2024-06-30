class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()){
            return 0;
        }
        int n=prices.size();
        vector<int> left(n,0);
        vector<int> right(n,0);
        
        int minprice=prices[0];        
        for(int i=1;i<n;++i){
            left[i]=max(left[i-1],prices[i]-minprice);
            minprice=min(minprice,prices[i]);
        }
        
        int maxprice=prices[n-1];
        for(int i=n-2;i>=0;--i){
            right[i]=max(right[i+1],maxprice-prices[i]);
            maxprice=max(maxprice,prices[i]);
        }
        
        int maxprofit=0;
        for(int i=0;i<n;++i){
            maxprofit=max(maxprofit,left[i]+right[i]);
        }
        return maxprofit;
        
    }
};


