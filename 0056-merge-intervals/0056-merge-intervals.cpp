class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        if(n<=1){
            return intervals;
        }
        
        sort(intervals.begin(),intervals.end());
        
        vector<vector<int>> mergedintervals;
        vector<int> current=intervals[0];
        
        for(int i=1;i<n;i++){
            if(intervals[i][0]<=current[1]){
                current[1]=max(current[1],intervals[i][1]);
            }else{
                mergedintervals.push_back(current);
                current=intervals[i];
            }
            
        }
        mergedintervals.push_back(current);
        return mergedintervals;
    }
};