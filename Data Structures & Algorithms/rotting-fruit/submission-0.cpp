class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        queue<vector<int>> q;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 2) {
                    q.push({i, j, 0});
                }
            }
        }

        int ans = 0;

        while (!q.empty()) {

            vector<int> curr = q.front();
            q.pop();

            int x = curr[0];
            int y = curr[1];
            int currTime = curr[2];

            ans = max(ans, currTime);

            int dx[] = {-1, 1, 0, 0};
            int dy[] = {0, 0, -1, 1};

            for (int d = 0; d < 4; d++) {

                int nx = x + dx[d];
                int ny = y + dy[d];

                // Outside grid
                if (nx < 0 || nx >= m || ny < 0 || ny >= n)
                    continue;

                // Fresh orange
                if (grid[nx][ny] == 1) {

                    grid[nx][ny] = 2;

                    q.push({nx, ny, currTime + 1});
                }
            }
        }

        // Check if still fresh orange exist
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {

                if (grid[i][j] == 1)
                    return -1;
            }
        }

        return ans;
    }
};