class Solution {
public:
bool fxn(int i,int j,int n,int m,int k,vector<vector<char>>& board, string word,vector<vector<int>>&vis){
    vis[i][j]=1;
    if(k==word.length()) return true;
if(i>0 &&  word[k]==board[i-1][j] && !vis[i-1][j]){
    if(fxn(i-1,j,n,m,k+1,board,word,vis)) return true;
    vis[i-1][j]=0;
} 
if(j>0 && word[k]==board[i][j-1] && !vis[i][j-1]){
    if(fxn(i,j-1,n,m,k+1,board,word,vis)) return true;
    vis[i][j-1]=0;
} 
if(j<m-1 && word[k]==board[i][j+1] && !vis[i][j+1]){
    if(fxn(i,j+1,n,m,k+1,board,word,vis)) return true;
    vis[i][j+1]=0;
} 
if(i<n-1 && word[k]==board[i+1][j] && !vis[i+1][j]){
    if(fxn(i+1,j,n,m,k+1,board,word,vis)) return true;
    vis[i+1][j]=0;
}
return false; 
}
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size(),m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                      vector<vector<int>>vis(n,vector<int>(m,0));
                    if(fxn(i,j,n,m,1,board,word,vis)) return true;
                }
            }
        }
        return false;
    }
};
