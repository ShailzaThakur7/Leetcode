class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        vector<int> result;
        vector<bool> used(n,false);
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(nums1[i]==nums2[j] && !used[j]){
                    result.push_back(nums1[i]);
                    used[j]=true;
                    break;
                }
            }
        }
        return result;
    }
};