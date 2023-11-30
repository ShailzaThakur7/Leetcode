class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        
        unordered_map<int,int> c;
        unordered_set<int> result;
        
        for(int num:nums){
            c[num]++;
            if(c[num]>nums.size()/3){
                result.insert(num);
            }
        }
        return vector<int>(result.begin(),result.end());
        
    }
};