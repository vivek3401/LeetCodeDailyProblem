class Solution {
public:
    void dfs(int src,int des,vector<vector<char>>& board){
        int n=board.size();
        int m=board[0].size();
        board[src][des]='#';
        int dr[]={-1,0,1,0};
        int dc[]={0,1,0,-1};
        for(int i=0;i<4;i++){
            int nr=src+dr[i];
            int nc=des+dc[i];
            if(nr>=0 && nc>=0 && nr<n && nc < m && board[nr][nc]=='O'){
                dfs(nr,nc,board);
            }
        }
    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        int srow=0,erow=n-1,scol=0,ecol=m-1;
        for(int i=0;i<m;i++){    // top
            if(board[srow][i]=='O'){
                dfs(srow,i,board);
            }
        }
        for(int i=0;i<n;i++){   // left
            if(board[i][ecol]=='O'){
                dfs(i,ecol,board);
            }
        }
        for(int i=m-1;i>=0;i--){   // bottom
            if(board[erow][i]=='O'){
                dfs(erow,i,board);
            }
        }
        for(int i=n-1;i>=0;i--){  // right
            if(board[i][scol]=='O'){
                dfs(i,scol,board);
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                if(board[i][j]=='#'){
                    board[i][j]='O';
                }
            }
        }
    }
};