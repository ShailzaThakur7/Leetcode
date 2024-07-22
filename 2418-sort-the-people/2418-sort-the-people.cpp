#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        // Step 1: Create a vector of pairs
        vector<pair<int, string>> people;
        for (size_t i = 0; i < names.size(); ++i) {
            people.emplace_back(heights[i], names[i]);
        }
        
        // Step 2: Sort the vector of pairs based on the height in descending order
        sort(people.begin(), people.end(), [](const pair<int, string>& a, const pair<int, string>& b) {
            return a.first > b.first;
        });
        
        // Step 3: Extract the names from the sorted vector of pairs
        vector<string> sortedNames;
        for (const auto& person : people) {
            sortedNames.push_back(person.second);
        }
        
        return sortedNames;
    }
};
