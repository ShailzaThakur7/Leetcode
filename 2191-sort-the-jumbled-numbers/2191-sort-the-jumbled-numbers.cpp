// class Solution {
// public:
//     vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
//         vector<pair<int,int>> v;
//         for(int i=0;i<nums.size();i++){
//             v.push_back({nums[i],i});
//         }
        
//         sort(v.begin(),v.end(),[&](pair<int,int> &a,pair<int,int> &b){
//             return mapping[a.first]<mapping[b.first];
//         });
        
//         vector<int> result;
//         for(int i=0;i<nums.size();i++){
//             result[i]=v[i].first;
//         }
//         return result;
        
//     }
// };
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        // Helper function to convert a number using the mapping
        auto convert = [&](int num) -> int {
            string numStr = to_string(num);
            string mappedStr;
            for (char c : numStr) {
                mappedStr += to_string(mapping[c - '0']);
            }
            return stoi(mappedStr);
        };
        
        // Create a vector of pairs (converted number, original index)
        vector<pair<int, int>> v;
        for (int i = 0; i < nums.size(); ++i) {
            v.emplace_back(convert(nums[i]), i);
        }
        
        // Sort the pairs based on the converted numbers
        sort(v.begin(), v.end());
        
        // Prepare the result vector with sorted numbers
        vector<int> result(nums.size());
        for (int i = 0; i < v.size(); ++i) {
            result[i] = nums[v[i].second];
        }
        
        return result;
    }
};
