class Solution {
public:
void dfs(int i,int j,   vector<vector<bool>>&vis,vector<vector<char>>& board,int n,int m){
    if(i<0 || j<0 || i>n-1 || j>m-1)return;
   if(board[i][j]=='X') return;
   if(vis[i][j]==false) return;
   vis[i][j]=false;
    dfs(i-1,j,vis,board,n,m);
     dfs(i+1,j,vis,board,n,m);
      dfs(i,j+1,vis,board,n,m);
       dfs(i,j-1,vis,board,n,m);
}
    void solve(vector<vector<char>>& board) {
     int n=board.size();
     int m=board[0].size();
     vector<vector<bool>>vis(n,vector<bool>(m,true));
     for(int i=0;i<n;i++){
       if(board[i][0]=='O' && vis[i][0]){
        dfs(i,0,vis,board,n,m);
       }
      if(board[i][m-1]=='O' && vis[i][m-1]){
        dfs(i,m-1,vis,board,n,m);
       }
     } 
      for(int j=0;j<m;j++){
       if(board[0][j]=='O' && vis[0][j]){
        dfs(0,j,vis,board,n,m);
       }
       if(board[n-1][j]=='O' && vis[n-1][j]){
        dfs(n-1,j,vis,board,n,m);
       }
     }
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if( board[i][j]=='O' && vis[i][j]){
                board[i][j]='X';
            }
        }
     }    
    }
};
