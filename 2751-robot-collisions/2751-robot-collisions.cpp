#include <vector>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> indices(n);
        for (int i = 0; i < n; ++i) indices[i] = i;
        
        // Sort robots by their positions
        sort(indices.begin(), indices.end(), [&](int a, int b) {
            return positions[a] < positions[b];
        });
        
        stack<int> st;
        for (int i : indices) {
            if (directions[i] == 'R') {
                st.push(i);
            } else {
                while (!st.empty() && directions[st.top()] == 'R') {
                    if (healths[st.top()] == healths[i]) {
                        // Both robots destroy each other
                        healths[st.top()] = 0;
                        healths[i] = 0;
                        st.pop();
                        break;
                    } else if (healths[st.top()] < healths[i]) {
                        // Right-moving robot is destroyed
                        healths[st.top()] = 0;
                        st.pop();
                        healths[i]--;
                    } else {
                        // Left-moving robot is destroyed
                        healths[i] = 0;
                        healths[st.top()]--;
                        break;
                    }
                }
                if (healths[i] > 0) {
                    st.push(i);
                }
            }
        }
        
        vector<int> survived;
        for (int i = 0; i < n; ++i) {
            if (healths[i] > 0) {
                survived.push_back(healths[i]);
            }
        }
        
        return survived;
    }
};
