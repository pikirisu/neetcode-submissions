class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int dr[4] = {0,1,0,-1};
        int dc[4] = {1,0,-1,0};
        int dir = 0;

        vector<int> ans;
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        int rows = 0;
        int cols = 0;

        for(int i=0; i<n*m; i++){

            ans.push_back(matrix[rows][cols]);
            visited[rows][cols]=true;

            int nr = rows + dr[dir];
            int nc = cols + dc[dir];

            if(nr<0 || nc< 0 || nr>= m || nc>=n || visited[nr][nc]){

                dir = (dir+1)%4;

                nr = rows + dr[dir];
                nc = cols + dc[dir];
            }

            rows = nr;
            cols = nc;
        }
        return ans;
    }
};
