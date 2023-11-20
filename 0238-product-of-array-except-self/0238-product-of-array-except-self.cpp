class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector <int> answer;
        int product=1,i;
        
        int n=nums.size();
        for(int i=0;i<n;i++){
            answer.push_back(product);
            product*=nums[i];            
        }
        product=1;
        for(int i=n-1;i>=0;i--){
            answer[i]*=product;
            product*=nums[i];
        }
        return answer;
        
    }
};