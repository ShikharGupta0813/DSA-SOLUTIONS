class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1)
            return -1;

        vector<vector<bool>> vis(n, vector<bool>(n, false));
        queue<pair<int, int>> q;

        int dx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
        int dy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

        q.push({0, 0});
        vis[0][0] = true;
        int steps = 1;

        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                auto [r, c] = q.front(); q.pop();
                if (r == n - 1 && c == n - 1) return steps;

                for (int i = 0; i < 8; ++i) {
                    int nr = r + dx[i];
                    int nc = c + dy[i];

                    if (nr >= 0 && nc >= 0 && nr < n && nc < n && !vis[nr][nc] && grid[nr][nc] == 0) {
                        vis[nr][nc] = true;
                        q.push({nr, nc});
                    }
                }
            }
            steps++;
        }

        return -1;
    }
};
