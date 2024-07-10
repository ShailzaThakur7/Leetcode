#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int n = grid.size(), m = grid[0].size();
        int startX, startY, total_keys = 0;
        vector<vector<vector<bool>>> visited(n, vector<vector<bool>>(m, vector<bool>(64, false))); // up to 6 keys

        // Find starting point and total keys
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '@') {
                    startX = i;
                    startY = j;
                } else if (islower(grid[i][j])) {
                    total_keys++;
                }
            }
        }

        queue<tuple<int, int, int, int>> q; // (x, y, keys, steps)
        q.emplace(startX, startY, 0, 0);
        visited[startX][startY][0] = true;

        int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int target = (1 << total_keys) - 1;

        while (!q.empty()) {
            auto [x, y, keys, steps] = q.front();
            q.pop();

            if (keys == target) {
                return steps;
            }

            for (auto& dir : directions) {
                int nx = x + dir[0];
                int ny = y + dir[1];
                int nkeys = keys;

                if (nx < 0 || ny < 0 || nx >= n || ny >= m || grid[nx][ny] == '#') {
                    continue;
                }

                char cell = grid[nx][ny];
                if (isupper(cell) && !(keys & (1 << (cell - 'A')))) {
                    continue; // lock and we don't have the key
                }
                if (islower(cell)) {
                    nkeys |= (1 << (cell - 'a'));
                }

                if (!visited[nx][ny][nkeys]) {
                    visited[nx][ny][nkeys] = true;
                    q.emplace(nx, ny, nkeys, steps + 1);
                }
            }
        }

        return -1;
    }
};
