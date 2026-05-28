class Solution {
public:
void dfs(int i,int j,vector<vector<int>>& grid, vector<vector<int>>&vis,int n,int m,int &c){
    vis[i][j]=1;
    if(i>0 && !vis[i-1][j] && grid[i-1][j]==1){
         c++;
        dfs(i-1,j,grid,vis,n,m,c);
    }
     if(j>0 && !vis[i][j-1] && grid[i][j-1]==1){
         c++;
        dfs(i,j-1,grid,vis,n,m,c);
    }
     if(i<n-1 && !vis[i+1][j] && grid[i+1][j]==1){
         c++;
        dfs(i+1,j,grid,vis,n,m,c);
    }
     if(j<m-1 && !vis[i][j+1] && grid[i][j+1]==1){
        c++;
        dfs(i,j+1,grid,vis,n,m,c);
    }
}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
         int n=grid.size();
        int m=grid[0].size();
        int maxi=INT_MIN;
        vector<vector<int>>vis(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
if(grid[i][j]==1 && !vis[i][j]){
     int c=1;
    dfs(i,j,grid,vis,n,m,c);
    maxi=max(maxi,c);
}
            }
        }
        if(maxi==INT_MIN) return 0;
        return maxi;
    }
};
