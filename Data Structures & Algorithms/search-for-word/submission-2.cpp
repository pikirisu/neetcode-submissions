class Solution {
public:
    bool solve(vector<vector<char>>& board, const string& word, int i, int j, int idx){
        
        if(idx==word.size())
        return true;
        
        if(i==board.size() || j==board[0].size() || i<0 || j<0)
        return false;

        if(board[i][j]=='#')
        return false;

        if(word[idx]!=board[i][j])
        return false;

        char store = board[i][j];
        board[i][j]='#';

        int dx[4] = {0,1,0,-1};
        int dy[4] = {1,0,-1,0};

        for(int k=0; k<4; k++){
            bool res = solve(board,word,i+dx[k],j+dy[k],idx+1);
            if(res==true)
            return true;
        }

        // Backtrack
        board[i][j] = store;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        for(int i=0 ; i<m; i++){
            for(int j=0; j<n; j++){
                if(solve(board,word,i,j,0))
                return true;
            }
        }

        return false;
    }
};
