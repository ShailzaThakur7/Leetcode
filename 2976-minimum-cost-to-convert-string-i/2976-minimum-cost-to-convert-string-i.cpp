class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        const int INF = 1e9;
        vector<vector<int>> minCost(26, vector<int>(26, INF));

        // Initialize the minCost matrix
        for (int i = 0; i < 26; ++i) {
            minCost[i][i] = 0;
        }

        // Populate the minCost matrix with given transformations
        for (int i = 0; i < original.size(); ++i) {
            int from = original[i] - 'a';
            int to = changed[i] - 'a';
            minCost[from][to] = min(minCost[from][to], cost[i]);
        }

        // Floyd-Warshall algorithm to find the shortest paths between all pairs of nodes
        for (int k = 0; k < 26; ++k) {
            for (int i = 0; i < 26; ++i) {
                for (int j = 0; j < 26; ++j) {
                    if (minCost[i][k] < INF && minCost[k][j] < INF) {
                        minCost[i][j] = min(minCost[i][j], minCost[i][k] + minCost[k][j]);
                    }
                }
            }
        }

        // Compute the minimum cost to convert source to target
        long long totalCost = 0;
        for (int i = 0; i < source.size(); ++i) {
            int from = source[i] - 'a';
            int to = target[i] - 'a';
            if (minCost[from][to] == INF) {
                return -1; // Impossible to transform
            }
            totalCost += minCost[from][to];
        }

        return totalCost;
    }
};
