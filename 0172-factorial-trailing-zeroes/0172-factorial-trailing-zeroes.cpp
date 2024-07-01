class Solution {
public:
    unsigned long long factorial(int n) {
    unsigned long long result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}
    int trailingZeroes(int n) {
        int count=0;
        while(n>=5){
            n/=5;
            count+=n;
        }
        return count;
        
        
        
    }
};