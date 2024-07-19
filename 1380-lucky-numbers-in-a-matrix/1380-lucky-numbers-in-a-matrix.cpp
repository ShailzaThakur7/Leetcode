class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        unordered_set<int> minrow;
        unordered_set<int> maxcol;
        vector<int> result;
        
        int rows=matrix.size();
        int cols=matrix[0].size();
        
        for(int i=0;i<rows;i++){
            int minrowvalue=*min_element(matrix[i].begin(),matrix[i].end());
            minrow.insert(minrowvalue);
        }
        
        for(int j=0;j<cols;j++){
            int maxcolvalue=matrix[0][j];
            for(int i=1;i<rows;i++){
                maxcolvalue=max(maxcolvalue,matrix[i][j]);
            }
            maxcol.insert(maxcolvalue);
            
        }
        
        for(const int& num:minrow){
            if(maxcol.find(num)!=maxcol.end()){
                result.push_back(num);
            }
        }
        return result;
        
    }
};