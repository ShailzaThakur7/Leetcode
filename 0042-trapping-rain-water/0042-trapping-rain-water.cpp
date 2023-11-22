class Solution {
public:
    int trap(vector<int>& height) {
        
        //limit to trap water
        int n=height.size();
        if(n<=2){
            return 0;
        }
        
        int left=0,right=n-1;
        int leftmax=0,rightmax=0;
        int trappedwater=0;
        
        while(left<right){
            leftmax=max(leftmax,height[left]);
            rightmax=max(rightmax,height[right]);
            
            if(height[left]<height[right]){
                trappedwater+=max(0,leftmax-height[left]);
                left++;
            }else{
                trappedwater+=max(0,rightmax-height[right]);
                right--;                
            }
        }
        return trappedwater;
        
    }
};