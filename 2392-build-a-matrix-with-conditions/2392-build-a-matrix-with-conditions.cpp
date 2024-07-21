#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> matrix(k, vector<int>(k, 0));
        
        auto topologicalSort = [&](vector<vector<int>>& conditions) {
            vector<int> indegree(k + 1, 0);
            vector<vector<int>> graph(k + 1);
            for (auto& cond : conditions) {
                graph[cond[0]].push_back(cond[1]);
                indegree[cond[1]]++;
            }
            
            queue<int> q;
            for (int i = 1; i <= k; i++) {
                if (indegree[i] == 0) {
                    q.push(i);
                }
            }
            
            vector<int> order;
            while (!q.empty()) {
                int node = q.front();
                q.pop();
                order.push_back(node);
                for (int neighbor : graph[node]) {
                    indegree[neighbor]--;
                    if (indegree[neighbor] == 0) {
                        q.push(neighbor);
                    }
                }
            }
            
            if (order.size() != k) return vector<int>(); // Cycle detected, invalid topological sort
            return order;
        };
        
        vector<int> rowOrder = topologicalSort(rowConditions);
        vector<int> colOrder = topologicalSort(colConditions);
        
        if (rowOrder.empty() || colOrder.empty()) return {}; // If either topological sort failed
        
        unordered_map<int, int> rowPosition, colPosition;
        for (int i = 0; i < k; i++) {
            rowPosition[rowOrder[i]] = i;
            colPosition[colOrder[i]] = i;
        }
        
        for (int i = 1; i <= k; i++) {
            matrix[rowPosition[i]][colPosition[i]] = i;
        }
        
        return matrix;
    }
};
