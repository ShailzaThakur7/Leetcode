class Solution {
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int,int> c;
        
        for(int num:nums){
            c[num]++;
            if(c[num]>nums.size()/2){
                return num;
            }
        }
        return -1;
        
    }
};