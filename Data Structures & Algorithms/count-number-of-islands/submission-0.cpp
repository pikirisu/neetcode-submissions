class Solution {
public:
    void dfs(vector<vector<char>>& grid,vector<vector<bool>>&visited,int i, int j){
        int m = grid.size();
        int n = grid[0].size();

        if(i<0 || i>=m || j<0 || j>=n) return;

        if(visited[i][j] || grid[i][j]=='0') return;

        visited[i][j] = true;

        int dx[4] = {0,1,0,-1};
        int dy[4] = {1,0,-1,0};

        for(int k=0; k<4; k++){
            dfs(grid,visited,i+dx[k],j+dy[k]);
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int count = 0;

        vector<vector<bool>>visited(m,vector<bool>(n,false));

        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j] && grid[i][j]=='1'){
                    count++;
                    dfs(grid,visited,i,j);
                }
            }
        }

        return count;
    }
};
