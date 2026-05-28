class Solution {
public:
void dfs(int i,int j,vector<vector<char>>& grid, vector<vector<int>>&vis,int n,int m){
    vis[i][j]=1;
    if(i>0 && !vis[i-1][j] && grid[i-1][j]=='1'){
        dfs(i-1,j,grid,vis,n,m);
    }
     if(j>0 && !vis[i][j-1] && grid[i][j-1]=='1'){
        dfs(i,j-1,grid,vis,n,m);
    }
     if(i<n-1 && !vis[i+1][j] && grid[i+1][j]=='1'){
        dfs(i+1,j,grid,vis,n,m);
    }
     if(j<m-1 && !vis[i][j+1] && grid[i][j+1]=='1'){
        dfs(i,j+1,grid,vis,n,m);
    }
}
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int c=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
if(grid[i][j]=='1' && !vis[i][j]){
    c++;
    dfs(i,j,grid,vis,n,m);
}
            }
        }
        return c;
    }
};
