class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result(nums1.size()+nums2.size());
        
        merge(nums1.begin(),nums1.end(),nums2.begin(),nums2.end(),result.begin());
        

        int n=result.size();
        
        if(n%2==1){
            return result[n/2];
        }else{
            return (result[n/2-1]+result[n/2])/2.0;
        }
    }
};