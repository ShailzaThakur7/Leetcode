// class Solution {
// public:
//     int mySqrt(int x) {
//         if(x<2){
//             return x;
//         }
        
//         int left=1,right=x,sqrt,mid;
        
//         while(left<=right){
//             mid=left+(right-left)/2;
//             sqrt=mid*mid;
//             if(sqrt==x){
//                 return mid;
//             }else if(sqrt<x){
//                 left=mid+1;
//             }else{
//                 right=mid-1;                
//             }
//         }
//         return right;
//     }
// };

class Solution {
public:
    int mySqrt(int x) {
        if (x < 2) return x;
        
        long left = 1, right = x, mid, sqrt;
        
        while (left <= right) {
            mid = left + (right - left) / 2;
            sqrt = mid * mid;
            
            if (sqrt == x) return mid;
            else if (sqrt < x) left = mid + 1;
            else right = mid - 1;
        }
        
        return right;
    }
};
