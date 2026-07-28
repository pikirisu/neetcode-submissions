class Solution {
   public:
    int solve(vector<vector<int>>& obstacleGrid, int r, int c) {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();

        if (obstacleGrid[r][c] == 1) return 0;

        if (r == rows - 1 && c == cols - 1) return 1;

        int right = 0;
        if (r + 1 < rows) {
            right = solve(obstacleGrid, r + 1, c);
        }

        int down = 0;
        if (c + 1 < cols) {
            down = solve(obstacleGrid, r, c + 1);
        }

        return down + right;
    }

    int solveMem(vector<vector<int>>& obstacleGrid, int r, int c, vector<vector<int>>& dp) {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();

        if (obstacleGrid[r][c] == 1) return 0;

        if (r == rows - 1 && c == cols - 1) return 1;

        if (dp[r][c] != -1) return dp[r][c];

        int right = 0;
        if (r + 1 < rows) {
            right = solveMem(obstacleGrid, r + 1, c, dp);
        }

        int down = 0;
        if (c + 1 < cols) {
            down = solveMem(obstacleGrid, r, c + 1, dp);
        }
        dp[r][c] = down + right;
        return dp[r][c];
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int rows = obstacleGrid.size();
        int cols = obstacleGrid[0].size();
        vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, -1));
        return solveMem(obstacleGrid, 0, 0,dp);
    }
};