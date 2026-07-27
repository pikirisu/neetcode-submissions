class Solution {
   public:
    void countPaths(int& paths, int m, int n, int rows, int cols) {
        if (m == rows && n == cols) {
            paths++;
            return;
        }

        if (m + 1 <= rows) {
            countPaths(paths, m + 1, n, rows, cols);
        }

        if (n + 1 <= cols) {
            countPaths(paths, m, n + 1, rows, cols);
        }
    }

    int countPaths(int m, int n, int rows, int cols) {
        if (m == rows && n == cols) {
            return 1;
        }
        int down = 0;
        if (m + 1 <= rows) {
            down = countPaths(m + 1, n, rows, cols);
        }
        int right = 0;
        if (n + 1 <= cols) {
            right = countPaths(m, n + 1, rows, cols);
        }

        return right + down;
    }

    int countPathsMem(int m, int n, int rows, int cols, vector<vector<int>>& dp) {
        if (m == rows && n == cols) {
            return 1;
        }

        if (dp[m][n] != -1) return dp[m][n];

        int down = 0;
        if (m + 1 <= rows) {
            down = countPathsMem(m + 1, n, rows, cols, dp);
        }
        int right = 0;
        if (n + 1 <= cols) {
            right = countPathsMem(m, n + 1, rows, cols, dp);
        }
        dp[m][n] = right + down;
        return dp[m][n];
    }

    int solveTab(int rows, int cols) {
        vector<vector<int>> dp(rows + 1, vector<int>(cols + 1, 1));
        dp[rows][cols] = 1;

        for (int i = rows-1; i >=0; i--) {
            for (int j = cols-1; j >=0; j--) {
                dp[i][j] = dp[i+1][j] + dp[i][j+1];
            }
        }
        return dp[0][0];
    }
    int uniquePaths(int m, int n) {
        // int paths = 0;
        int rows = m - 1;
        int cols = n - 1;
        // vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        // return countPathsMem(0, 0, rows, cols, dp);
        return solveTab(rows,cols);
    }
};
